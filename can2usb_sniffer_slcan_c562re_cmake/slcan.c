/*
 * slcan.c
 *
 *  Created on: Apr 23, 2026
 *      Author: Bartek
 */

#include "slcan.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

hal_fdcan_handle_t *hfdcan1;
hal_fdcan_rx_header_t rx_header;
uint8_t rxData[8];
hal_fdcan_global_filter_config_t global_filter_config;
hal_fdcan_filter_t filter_config;

hal_uart_handle_t *huart2;

void sniffer_can_config(void) {
  hfdcan1 = mx_fdcan1_gethandle();
  global_filter_config.acceptance_non_matching_ext = HAL_FDCAN_NO_MATCH_REJECT;
  global_filter_config.acceptance_non_matching_std = HAL_FDCAN_NO_MATCH_REJECT;
  global_filter_config.acceptance_remote_ext = HAL_FDCAN_REMOTE_REJECT;
  global_filter_config.acceptance_remote_std = HAL_FDCAN_REMOTE_REJECT;
  if (HAL_FDCAN_SetGlobalFilter(hfdcan1, &global_filter_config) != HAL_OK) {
    FDCAN_Error_Handler();
  };

  filter_config.id_type = HAL_FDCAN_ID_STANDARD;
  filter_config.filter_index = 0;
  filter_config.filter_type = HAL_FDCAN_FILTER_TYPE_RANGE;
  filter_config.filter_config = HAL_FDCAN_FILTER_TO_RX_FIFO_0;
  filter_config.filter_id1 = 0x000;
  filter_config.filter_id2 = 0x7FF;
  if (HAL_FDCAN_SetFilter(hfdcan1, &filter_config) != HAL_OK) {
    FDCAN_Error_Handler();
  };

  if (HAL_FDCAN_Start(hfdcan1) != HAL_OK) {
    FDCAN_Error_Handler();
  };
}

void HAL_FDCAN_RxFifo0Callback(hal_fdcan_handle_t *hfdcan,
                               uint32_t rx_fifo0_interrupts) {
  // https://community.st.com/t5/stm32-mcus/understanding-fdcan-interrupts-grouping-in-applicable-stm32-mcus/ta-p/852823
  if (rx_fifo0_interrupts & HAL_FDCAN_IT_GROUP_RX_FIFO_0) {
    if (HAL_FDCAN_GetReceivedMessage(hfdcan1, HAL_FDCAN_RX_FIFO_0, &rx_header,
                                     rxData) == HAL_OK) {
      huart2 = mx_usart2_uart_gethandle();
      char slcan_str[64];
      uint16_t slcan_size;
      switch (rx_header.b.data_length) {
      case 1:
        slcan_size = sprintf(slcan_str, "t%x%x%x%02x%04x\r",
                             (rx_header.b.identifier >> 8) & 0x0F,
                             rx_header.b.identifier & 0xFF, 1, rxData[0],
                             (uint16_t)HAL_GetTick());
        break;
      case 2:
        slcan_size = sprintf(slcan_str, "t%x%x%x%02x%02x%04x\r",
                             (rx_header.b.identifier >> 8) & 0x0F,
                             rx_header.b.identifier & 0xFF, 2, rxData[0],
                             rxData[1], (uint16_t)HAL_GetTick());
        break;
      case 3:
        slcan_size = sprintf(slcan_str, "t%x%x%x%02x%02x%02x%04x\r",
                             (rx_header.b.identifier >> 8) & 0x0F,
                             rx_header.b.identifier & 0xFF, 3, rxData[0],
                             rxData[1], rxData[2], (uint16_t)HAL_GetTick());
        break;
      case 4:
        slcan_size =
            sprintf(slcan_str, "t%x%x%x%02x%02x%02x%02x%04x\r",
                    (rx_header.b.identifier >> 8) & 0x0F,
                    rx_header.b.identifier & 0xFF, 4, rxData[0], rxData[1],
                    rxData[2], rxData[3], (uint16_t)HAL_GetTick());
        break;
      case 5:
        slcan_size =
            sprintf(slcan_str, "t%x%x%x%02x%02x%02x%02x%02x%04x\r",
                    (rx_header.b.identifier >> 8) & 0x0F,
                    rx_header.b.identifier & 0xFF, 5, rxData[0], rxData[1],
                    rxData[2], rxData[3], rxData[4], (uint16_t)HAL_GetTick());
        break;
      case 6:
        slcan_size = sprintf(slcan_str, "t%x%x%x%02x%02x%02x%02x%02x%02x%04x\r",
                             (rx_header.b.identifier >> 8) & 0x0F,
                             rx_header.b.identifier & 0xFF, 6, rxData[0],
                             rxData[1], rxData[2], rxData[3], rxData[4],
                             rxData[5], (uint16_t)HAL_GetTick());
        break;
      case 7:
        slcan_size = sprintf(
            slcan_str, "t%x%x%x%02x%02x%02x%02x%02x%02x%02x%04x\r",
            (rx_header.b.identifier >> 8) & 0x0F, rx_header.b.identifier & 0xFF,
            7, rxData[0], rxData[1], rxData[2], rxData[3], rxData[4], rxData[5],
            rxData[6], (uint16_t)HAL_GetTick());
        break;
      case 8:
        slcan_size = sprintf(
            slcan_str, "t%x%x%x%02x%02x%02x%02x%02x%02x%02x%02x%04x\r",
            (rx_header.b.identifier >> 8) & 0x0F, rx_header.b.identifier & 0xFF,
            8, rxData[0], rxData[1], rxData[2], rxData[3], rxData[4], rxData[5],
            rxData[6], rxData[7], (uint16_t)HAL_GetTick());
        break;
      default:
        break;
      }
      HAL_UART_Transmit_DMA(huart2, slcan_str, slcan_size);
      HAL_GPIO_TogglePin(LD1_PORT, LD1_PIN);
    }
  }
}

void FDCAN_Error_Handler(void) {
  while (1) {
    // Choose your favorite way to go into the panic mode :)
  }
}
