/*  LCD_ST7032.h -- driver for (eg) Newhaven LCDs which use 4-wire
    ST7032 interface.

    Based on derived classes from https://bitbucket.org/fmalpartida/new-liquidcrystal
      Created by Francisco Malpartida on 20/08/11.
      Copyright 2011 - Under creative commons license 3.0:
        Attribution-ShareAlike CC BY-SA)

    TODO: implement an "LCD on", such that you can power down the LCD entirely
    when not in use. (if desired...)
*/

#ifndef LCD_SSD1311_H
#define LCD_SSD1311_H

#include <Arduino.h>
#include <SPI.h>

#include "LCDStream.h"

class LCD_SSD1311 : public LCD
{
public:
  LCD_SSD1311(uint8_t pin_cs);

  virtual void send(uint8_t value, uint8_t mode);

  virtual void begin(uint8_t cols = 8, uint8_t rows = 2, uint8_t charsize = LCD_5x8DOTS);
  virtual void setCursor(uint8_t col, uint8_t row);

private:
  void init();

  uint8_t _rst, _rs, _cs, _rows, _cols;
  SPISettings _spi_settings;
};

#endif
