# Performance Testing of FLoWRTOS
The testing on the Udoo Neo board with specifications:
* CPU : NXP™ i.MX 6SoloX applications processor with an embedded ARM Cortex-A9 core & a Cortex-M4 Core
* RAM : DDR3 1GB
* OS : Linux UDOObuntu2 (14.04 LTS)

## Edit Project Directory
Change and adjust your project directory in the CMakeList file in the armgcc directory

## Commands for Project Compilation
```
#!/bin/sh
cd /home/<username>/<your directory>/BSP_1.0.1_iMX6SX/<your project directory>/armgcc
export ARMGCC_DIR=/opt/gcc-arm-none-eabi-7-2017-q4-major #adjust to your version of gcc-arm-none-eabi
./clean.sh
.build.sh
```

## Command for Move Firmware
```
#!/bin/sh
sudo rm /media/<username>/boot/<compilation name>.bin
cd /home/<username>/<your directory>/BSP_1.0.1_iMX6SX/<your project directory>/armgcc/debug
sudo cp <compilation name>.bin /media/<username>/boot/<compilation name>.bin
```

## Command for Upload Firmware
```
sudo ./upload <compilation name>.bin 0x007f800
```

The  testing  is conducted  by  focusing  on  evaluating the performance of the FLoWRTOS kernel, by using a plant and without using a plant. The results of the performance test can be seen in more detail in the publication:
* [IEEE][ieee-url]
* [Scopus][scopus-url]
* [ResearchGate][researchGate-url]

<!-- MARKDOWN LINKS -->
[ieee-url]: https://ieeexplore.ieee.org/document/8628544/
[scopus-url]: https://www.mendeley.com/catalogue/aa41ee16-69b3-33bb-b783-95d87d85bae2/
[researchGate-url]: https://www.researchgate.net/publication/330792251_Development_and_Performance_Testing_of_FLoWRTOS_with_Random_Case_3_Main_Processes_on_The_Head_System_of_T-FLoW_Robot/
