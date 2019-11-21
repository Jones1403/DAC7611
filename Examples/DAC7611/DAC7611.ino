

//Release Date: 21-11-2019
//gladeines@gmail.com

/*===========================================================================
DAC7611 device library code is placed under the MIT license
Copyright (c) 2019 Jona Gladines

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================*/

//The DAC7611 is a 12-bit digital-to-analog converter
//(DAC) with guaranteed 12-bit monotonicity performance over the industrial temperature range. 
//It requires a single +5V supply and contains an input shift
//register, latch, 2.435V reference, DAC, and high speed
//rail-to-rail output amplifier. 

//This library is enhanced with the SPI library to make use of the speed of the SPI bus of the Arduino.
//CLK == 13;
//SDI == 11; 
//To operate the DAC, first create an instance of the DAC using DAC7611 dac(cs, ld, clr)
//next initialise the dac using begin() and send data 
//analogWrite(int value)

#include <DAC7611.h>

uint8_t cs = 8;
uint8_t ld = 2;
uint8_t clr = 3;

DAC7611 dac(cs, ld, clr);

int dacVal = 0;

void setup()
{
  Serial.begin(9600);
  dac.begin();  //initialise DAC
  Serial.println("Hello");  
}

void loop()
{
  if (Serial.available() > 0)
  {
    dacVal = Serial.parseInt();
    dac.analogWrite(dacVal);  //send values to DAC
    Serial.print("DAC Value is : ");  
    Serial.println(dacVal);
  }
  delay(1000);
}