#include "DAC7611.h"
#include <SPI.h>

DAC7611::DAC7611(uint8_t cs, uint8_t ld, uint8_t clr){
  _cs = cs;
  _ld = ld;
  _clr = clr;
}

void DAC7611::begin(void){
  //Prepare SPI
  SPI.begin();
  pinMode(_cs, OUTPUT);
  pinMode(_ld, OUTPUT);
  pinMode(_clr, OUTPUT);
  digitalWrite(_cs, HIGH);
  digitalWrite(_ld, HIGH);
  digitalWrite(_clr, HIGH);
}

void DAC7611::analogWrite(uint16_t value)
{
  
    // Prepare the buffer make sure value is smaller than 4095
    value = (value & 0xfff) >> 1;

    //make shift register invisible for dac register
    digitalWrite(_ld, HIGH); 
    // Assert SPI bus
    digitalWrite(_cs, LOW);
    
    // Perform SPI Transfer
    SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
    SPI.transfer16(value);
    SPI.endTransaction();
    
    // Deassert SPI bus
    digitalWrite(_cs, HIGH);

    //latch dac register
    digitalWrite(_ld, LOW);
}

void DAC7611::reset(void){
  digitalWrite(_clr, LOW);
  delayMicroseconds(1);
  digitalWrite(_clr, HIGH);
  digitalWrite(_cs, HIGH);
  digitalWrite(_ld, HIGH);
}
