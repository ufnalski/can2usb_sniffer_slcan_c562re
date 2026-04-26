# CAN2USB converter/sniffer compatible with SavvyCAN (Lawicel SLCAN protocol) [STM32C562RE]

![STM32/MX2/HAL2 CAN bus sniffer project](/Assets/Images/can_bus_sniffer_mx2.JPG)

Do you need a CAN bus sniffer? Do you need it badly? Is waiting two days to get e.g. [CANable](https://makerbase3d.com/product/makerbase-canable-v2/) not an aption for you? No worries. Just grab a Nucleo borad and a CAN transceiver, or preferrably the [NUCLEO-C562RE](https://www.st.com/en/evaluation-tools/nucleo-c562re.html) with the CAN transceiver already fitted on the board, and make your own sniffer compatible with [SavvyCAN](https://github.com/collin80/SavvyCAN). Thank you Collin Kidder! My code is an extreme version of a minimum viable product (MVP) - it supports only one hard-coded CAN baud rate and provides only reading frames from the bus, i.e. the listen-only (LO) mode. The implementation of the complete protocol is on you :slightly_smiling_face: The sniffer was tested in the system shown [here](https://github.com/ufnalski/peugeot_207_ipc_barebone_c562re). Have fun with sniffing and reverse engineering!

![STM32/MX2/HAL2 CAN bus sniffer in action](/Assets/Images/can_bus_sniffer_mx2_in_action.jpg)
![STM32/MX2/HAL2 CAN bus sniffer and SavvyCAN](/Assets/Images/savvycan_slcan_stm32c562re_sniffer.JPG)

# Missing files?
Don't worry. Just open the .ioc2 file in STM32CubeMX2 and hit the yellow button to generate the IDE project. Then open the project in STM32CubeIDE for Visual Studio Code and build it.

# SLCAN protocol
* [LAWICEL CAN Tools](https://www.canusb.com/) (ELMICRO Computer)
* [Library for Lawicel SLCAN Protocol (Serial-Line CAN)](https://github.com/mac-can/SLCAN) (Uwe Vogt, mac-can)
* [lawicel-slcan](https://github.com/darauble/lawicel-slcan) (Darau, Ble, darauble)
* [CAN232 Version 3 Manual](http://www.can232.com/docs/can232_v3.pdf) (LAWICEL CANUSB)
* [EVTV Motor Verks](https://www.youtube.com/evtvmotors)
* [EVTV Blog](https://www.evtv.me/writers/collin-kidder) (Collin Kidder)
* [arduino-canbus-monitor](https://github.com/latonita/arduino-canbus-monitor) (Anton Viktorov, latonita)
* [SLGreen](https://github.com/renardspark/SLGreen) (renardspark)

# Call to action
Create your own [home laboratory/workshop/garage](http://ufnalski.edu.pl/control_engineering_for_hobbyists/2025_dzien_popularyzacji_matematyki/Dzien_Popularyzacji_Matematyki_2025.pdf)! Get inspired by [ControllersTech](https://www.youtube.com/@ControllersTech), [DroneBot Workshop](https://www.youtube.com/@Dronebotworkshop), [Andreas Spiess](https://www.youtube.com/@AndreasSpiess), [GreatScott!](https://www.youtube.com/@greatscottlab), [bitluni's lab](https://www.youtube.com/@bitluni), [ElectroBOOM](https://www.youtube.com/@ElectroBOOM), [Phil's Lab](https://www.youtube.com/@PhilsLab), [atomic14](https://www.youtube.com/@atomic14), [That Project](https://www.youtube.com/@ThatProject), [Paul McWhorter](https://www.youtube.com/@paulmcwhorter), [Max Imagination](https://www.youtube.com/@MaxImagination), [Nikodem Bartnik](https://www.youtube.com/@nikodembartnik), [Stuff Made Here](https://www.youtube.com/@StuffMadeHere), [Mario's Ideas](https://www.youtube.com/@marios_ideas), [Aaed Musa](https://www.aaedmusa.com/), [Haase Industries](https://www.youtube.com/@h1tec), and many other professional hobbyists sharing their awesome projects and tutorials! Shout-out/kudos to all of them! Promote [README-driven learning](http://ufnalski.edu.pl/proceedings/sene2025/Ufnalski_PE_formatted_SENE_2025.pdf).

> [!WARNING]
> STM32C5 series - do try it at home :grey_exclamation:

220+ challenges to start from: [Control Engineering for Hobbyists at the Warsaw University of Technology](http://ufnalski.edu.pl/control_engineering_for_hobbyists/Control_Engineering_for_Hobbyists_list_of_challenges.pdf).

Stay tuned!

0xBU
