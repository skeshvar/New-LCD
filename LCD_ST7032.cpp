#include "SSD1311.h"


SSD1311::SSD1311(uint8_t pin_rst, uint8_t pin_rs, uint8_t pin_cs) :
  _rst(pin_rst), _rs(pin_rs), _cs(pin_cs)
{
  _spi_settings = SPISettings(500000, LSBFIRST, SPI_MODE3);
}


void SSD1311::init(){
  pinMode(_rst, OUTPUT);
  pinMode(_cs, OUTPUT);
  pinMode(_rs, OUTPUT);

  digitalWriteFast(_rst, HIGH);
  digitalWriteFast(_rs, HIGH);
  digitalWriteFast(_cs, HIGH);

  digitalWriteFast(_rst, LOW);
  delay(2);
  //send(0x30, COMMAND); // wakeup
  delay(2);
  digitalWriteFast(_rst, HIGH);
  
  
  command(0x3A);    //Function set: N=1 BE=0 RE=1 IS=0
  command(0x09);    //4-line mode
  command(0x05);    //view 0
  command(0x38);    //FunctionSet: N=1 DH=0 RE=0 IS=0
  command(0x3A);    //FunctionSet: N=1 BE=0 
  command(0x72);    //ROM selection
  data(0x01);       //ROM_A = 0x00, ROM_B = 0x04, ROM_C = 0x0c
  command(0x38);    //FunctionSet: N=1, DH=0, IS=0
  command(0x0C);    //Display blink cursor on
  command(0x01);    //Clear Display

  
  delay(10);
}

void SSD1311::begin(uint8_t rows, uint8_t cols, uint8_t dotsize){
  SPI.begin();
  init();
  // do we need to call parent begin??
  LCD::begin(rows, cols, dotsize);
  clear();
  setCursor(0,0);
}

void SSD1311::send(uint8_t value, uint8_t mode){
  // send mode => RS pin
  // LOW: command; HIGH: data
  bool send_mode = ( mode == DATA );

  noInterrupts();
  SPI.beginTransaction(_spi_settings);
  digitalWriteFast(_cs, LOW);
  digitalWriteFast(_rs, send_mode);
  delayMicroseconds(150); // do we need this?
  SPI.transfer(value);
  delayMicroseconds(150); // do we need this?
  SPI.endTransaction();
  digitalWriteFast(_cs, HIGH);
  interrupts();
}
