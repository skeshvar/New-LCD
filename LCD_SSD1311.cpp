#include "LCD_SSD1311.h"


LCD_SSD1311::LCD_SSD1311(uint8_t pin_rst, uint8_t pin_rs, uint8_t pin_cs) :
  _rst(pin_rst), _rs(pin_rs), _cs(pin_cs)
{
  _spi_settings = SPISettings(500000, LSBFIRST, SPI_MODE3);
}



void LCD_SSD1311::init(){
  pinMode (_cs, OUTPUT);
  digitalWrite(_cs,HIGH);
  delay(1);
  // initialize SPI:
  
  
  send(0x3A, 0);    //Function set: N=1 BE=0 RE=1 IS=0
  send(0x09, 0);    //4-line mode
  send(0x05, 0);    //view 0
  send(0x38, 0);    //FunctionSet: N=1 DH=0 RE=0 IS=0
  send(0x3A, 0);    //FunctionSet: N=1 BE=0 
  send(0x72, 0);    //ROM selection
  send(0x01, 1);       //ROM_A = 0x00, ROM_B = 0x04, ROM_C = 0x0c
  send(0x38, 0);    //FunctionSet: N=1, DH=0, IS=0
  send(0x0C, 0);    //Display blink cursor on
  send(0x01, 0);    //Clear Display

  
  delay(10);
}

void LCD_SSD1311::begin(uint8_t rows, uint8_t cols, uint8_t dotsize){
  //SPI.begin();
  init();
  // do we need to call parent begin??
  LCD::begin(rows, cols, dotsize);
}

void LCD_SSD1311::send(uint8_t value, uint8_t mode){
 uint8_t buf[3];

  buf[0] =  0x1F | (mode<<6); //This is the preamble
  buf[1] = value & 0x0F; //This is 0000 D3 D2 D1 D0
  buf[2] = (value>>4) & 0x0F; //This is 0000 D7 D6 D5 D4
  
  SPI.beginTransaction(SPISettings(500000, LSBFIRST, SPI_MODE3));
  digitalWrite(_cs,LOW);
  SPI.transfer(buf,3);
  digitalWrite(_cs,HIGH);
  SPI.endTransaction();
}


void LCD_SSD1311::setCursor(uint8_t col, uint8_t row)
{
  const int row_lenght = 0x20;
  int loc;
  loc = row*row_lenght+ col;
  send(0x80 | loc, 0);
  }

  
