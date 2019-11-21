#ifndef DAC7611_H
#define DAC7611_H

#include<Arduino.h>

class DAC7611
{
  private:
    const uint8_t _cs;  //chip  select
    const uint8_t _ld;  //latch
    const uint8_t _clr; //clear output
    
  public:
    DAC7611(uint8_t cs, uint8_t ld, uint8_t clr);

    void begin(void);
    void analogWrite(uint16_t value);
    void reset(void);
};

#endif //DAC7611_H
