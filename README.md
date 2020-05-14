# FootSensors with RL78/G10 software library (Rev.20200416)

This is a project to use Force Sensing Registors with RL78/G10
included with CS+ environment setting files provided by Renesas Electronics Corp.
So you can easily modify and add this codes with CS+ on Windows PC.
  
Let's enjoy it !

## Information for target board

RL78/G10 board "AE-R5F10Y47ASP" is provided by Akizukidenshi in Japan.
  
JPN : http://akizukidenshi.com/catalog/g/gK-09035/
  

## Installation

Import this project into CS+.
  

## Usage

The protocol stack is defined with an ICS3.5 provided by KONDO Kagaku.
ICS3.5 uses "Data=8bit, Stop=1bit, Parity=EVEN, baudrate=1.5Mbps."
You will get 4 sensor unit data when master MCU/MPU send 4 bytes data as follows :
|Command|SC|Address|Length|
|-------|--|-------|------|
|0xA0+ID|0x7F|0(fiexed)|4(fiexed)|
  
ID is defined as D_MY_ID in "cg_src/r_cg_userdefine.h".
  

## Current Support Peripherals

|Function Name        | Pin Name        | notes |
|:--------------------|:---------------:|:------|
|Analog Input         |P02/ANI1         | connecting to one of Force Sensing Registor with pulled up to 3.3V | 
|Analog Input         |P03/ANI2         | connecting to one of Force Sensing Registor with pulled up to 3.3V | 
|Analog Input         |P04/ANI3         | connecting to one of Force Sensing Registor with pulled up to 3.3V | 
|Analog Input         |P05/ANI4         | connecting to one of Force Sensing Registor with pulled up to 3.3V | 
|UART I/F             |P00/TxD0         | connecting to RxD of master MCU/MPU | 
|UART I/F             |P01/RxD0         | connecting to TxD of master MCU/MPU | 
|X'tal                |X1,X2            | mounted on board |
|OCD Debugger I/F     |RESET, TOOL0     | connecting to DEBUGGER |
|Non Connections      |P06, P07, P41    | |
