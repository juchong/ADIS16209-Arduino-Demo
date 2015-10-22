////////////////////////////////////////////////////////////////////////////////////////////////////////
//  October 2015
//  Author: Juan Jose Chong <juan.chong@analog.com>
////////////////////////////////////////////////////////////////////////////////////////////////////////
//  ADIS16209.h
////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  This library provides all the functions necessary to interface the ADIS16209 Inclinometer with an 
//  8-Bit Atmel-based Arduino development board. Functions for SPI configuration, reads and writes,
//  and scaling are included. This library may be used for the entire ADIS1620x family of devices 
//  with some modification.
//
//  This example is free software. You can redistribute it and/or modify it
//  under the terms of the GNU Lesser Public License as published by the Free Software
//  Foundation, either version 3 of the License, or any later version.
//
//  This example is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
//  FOR A PARTICULAR PURPOSE.  See the GNU Lesser Public License for more details.
//
//  You should have received a copy of the GNU Lesser Public License along with 
//  this example.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ADIS16209_h
#define ADIS16209_h
#include "Arduino.h"
#include <SPI.h>

// User Register Memory Map from Table 6
#define ENDURANCE 0x00  //Flash memory write count
#define SUPPLY_OUT 0x02 //Power supply measurement output
#define XACCL_OUT 0x04  //X-axis accelerometer output
#define YACCL_OUT 0x06  //Y-axis accelerometer output
#define AUX_ADC 0x08    //Auxialiary ADC output
#define TEMP_OUT 0x0A   //Temperature output
#define XINCL_OUT 0x0C  //X-axis inclinometer ouput, horizontal
#define YINCL_OUT 0x0E  //Y-axis inclinometer ouput, horizontal
#define ROT_OUT 0x10    //Vertical orientation output
#define XACCL_NULL 0x12 //X-axis accelerometer offset correction factor
#define YACCL_NULL 0x14 //Y-axis accelerometer offset correction factor
#define XINCL_NULL 0x16 //X-axis inclinometer offset correction factor
#define YINCL_NULL 0x18 //Y-axis inclinometer offset correction factor
#define ROT_NULL 0x1A   //Vertical orientation offset correction factor
#define ALM_MAG1 0x20   //Alarm 1 amplitude threshold
#define ALM_MAG2 0x22   //Alarm 2 amplitude threshold
#define ALM_SMPL1 0x24  //Alarm 1 sample size/time
#define ALM_SMPL2 0x26  //Alarm 2 sample size/time
#define ALM_CTRL 0x28   //Alarm control
#define AUX_DAC 0x30    //Auxilary DAC data input
#define GPIO_CTRL 0x32  //GPIO control
#define MSC_CTRL 0x34   //MISC control
#define SMPL_PRD 0x36   //Sample clock/Decimation filter control
#define AVG_CNT 0x38    //Average count control (filter setting)
#define SLP_CNT 0x3A    //Sleep mode control
#define STATUS 0x3C     //System status (error flags)
#define COMMAND 0x3E    //System global commands
#define PROD_ID 0x4A   //Product identifier (16,209 = 0x3F51)

// ADIS16209 Class Definition
class ADIS16209{

public:
  // ADIS16209 Constructor (ChipSelect, DataReady, Reset Pins)
  ADIS16209(int CS, int DR, int RST);

  // Destructor
  ~ADIS16209();

  // Performs hardware reset. Delay in miliseconds. Returns 1 when complete.
  int resetDUT(uint8_t ms);

  // Sets SPI bit order, clock divider, and data mode. Returns 1 when complete.
  int configSPI();

  // Reads register (two bytes) Returns signed 16 bit data.
  int16_t regRead(uint8_t regAddr);

  // Write register (two bytes). Returns 1 when complete.
  int regWrite(uint8_t regAddr, int16_t regData);

  // Scale accelerometer data. Returns scaled data as float.
  float accelScale(int16_t sensorData);

  // Scale incline data. Returns scaled data as float.
  float inclineScale(int16_t sensorData);

  // Scale temperature data. Returns scaled data as float.
  float tempScale(int16_t sensorData);

  // Scale VDD supply. Returns scaled data as float.
  float supplyScale(int16_t sensorData);

  
private:
  //Variables to store hardware pin assignments.
  int _CS;
  int _DR;
  int _RST;

};

#endif