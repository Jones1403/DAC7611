# SPI-DAC7611
A library based on the Arduino Platform to use the 12bit DAC by Texas Instruments.

The DAC7611 is a 12-bit digital-to-analog converter
with guaranteed 12-bit monotonicity performance over the industrial temperature range. 
It requires a single +5V supply and contains an input shift register, latch, 2.435V reference, DAC, and high speed rail-to-rail output amplifier. 

This library is enhanced with the SPI library to make use of the speed of the SPI bus of the Arduino.
  CLK == 13;
  SDI == 11; 

To operate the DAC, first create an instance of the DAC using DAC7611 dac(cs, ld, clr)
next initialise the dac using dac.begin() and send data with dac.analogWrite(int value)
