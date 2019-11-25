/*
Release Date: 21-11-2019
gladeines@gmail.com

The DAC7611 is a 12-bit digital-to-analog converter
(DAC) with guaranteed 12-bit monotonicity performance over the industrial temperature range. 
It requires a single +5V supply and contains an input shift
register, latch, 2.435V reference, DAC, and high speed
rail-to-rail output amplifier. 

 The circuit:
 * DAC7611 attached to SPI bus as follows:
 ** SDI - pin 11
 ** CLK - pin 13
 ** CS - pin 8
 ** LD - pin 3
 ** CLR - pin 2

To operate the DAC, first create an instance of the DAC using DAC7611 dac(cs, ld, clr)
next initialise the dac using begin() and send data 
analogWrite(int value)
*/

#include <DAC7611.h>

uint8_t cs = 8;
uint8_t ld = 3;
uint8_t clr = 2;

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