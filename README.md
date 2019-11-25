# Arduino SPI-DAC7611 Library


## Description
This is a small and simple library to control the DAC7611 digital to analog converter (DACs) with an Arduino board.

The DAC7611 is a 12-bit digital-to-analog converter
with guaranteed 12-bit monotonicity performance over the industrial temperature range. 
It requires a single +5V supply and contains an input shift register, latch, 2.435V reference, DAC, and high speed rail-to-rail output amplifier. 


## Installation

1. Navigate to the Releases page.
2. Download the latest release.
3. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library and select the file downloaded.

You can find more information on installing Arduino libraries [here](https://www.arduino.cc/en/Guide/Libraries).

## Usage Example
To operate the DAC, first create an instance of the DAC using DAC7611 dac(cs, ld, clr)
next initialise the dac using dac.begin() and send data with dac.analogWrite(int value)

```
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
```

## Dependencies

This library depends on the standard [SPI](https://www.arduino.cc/en/Reference/SPI) library.


## Licensing
The code in this project is licensed under MIT license.




