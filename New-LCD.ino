#include <SPI.h>
#include "LCD.h"

#define LCD_RST 0
#define LCD_RS  1
#define LCD_CS  10
/*
This is just examples.
*/

LCD_SSD1311 lcd( LCD_CS );


void Logo(){

uint8_t map0[8] = {0b00010011,
                   0b00010011,
                   0b00011111,
                   0b00011111,
                   0b00010011,
                   0b00010011,
                   0b00010010,
                   0b00010010};

uint8_t map1[8] = {0b00010010,
                   0b00010010,
                   0b00010011,
                   0b00010011,
                   0b00010011,
                   0b00010011,
                   0b00010011,
                   0b00010011};  
                     
uint8_t map2[8] = {0b00010011,
                   0b00000111,
                   0b00001111,
                   0b00011111,
                   0b00011111,
                   0b00011111,
                   0b00011111,
                   0b00011111};   

uint8_t map3[8] = {0b00011111,
                   0b00011111,
                   0b00011111,
                   0b00011111,
                   0b00010000,
                   0b00000000,
                   0b00000110,
                   0b00001111};                                  

uint8_t map4[8] = {0b00001111,
                   0b00000110,
                   0b00000000,
                   0b00010000,
                   0b00011111,
                   0b00011111,
                   0b00011111,
                   0b00011111};  
                      
uint8_t map5[8] = {0b00011100,
                   0b00011100,
                   0b00011111,
                   0b00011111,
                   0b00000100,
                   0b00000100,
                   0b00000100,
                   0b00000100};  
                      
uint8_t map6[8] = {0b00000100,
                   0b00000100,
                   0b00000100,
                   0b00000100,
                   0b00000100,
                   0b00000100,
                   0b00000100,
                   0b00000111};  

uint8_t map7[8] = {0b00000111,
                   0b00000111,
                   0b00000111,
                   0b00000111,
                   0b00001111,
                   0b00011111,
                   0b00011111,
                   0b00011111};                      
                                 
lcd.createChar((uint8_t)0, map0);
lcd.createChar((uint8_t)1, map1);
lcd.createChar((uint8_t)2, map2);
lcd.createChar((uint8_t)3, map3);
lcd.createChar((uint8_t)4, map4);
lcd.createChar((uint8_t)5, map5);
lcd.createChar((uint8_t)6, map6);
lcd.createChar((uint8_t)7, map7);

for (int i=0; i<4; i++)
{
  for (int j=0; j<7; j++)
  {
    lcd.setCursor(j,i);
    lcd.write((uint8_t)31);
  }
}
int col = 2;

lcd.setCursor(col,1);
lcd.write((uint8_t)0);
lcd.setCursor(col,2);
lcd.write((uint8_t)1);
lcd.setCursor(col,3);
lcd.write((uint8_t)2);

lcd.setCursor(col+1,1);
lcd.write((uint8_t)3);
lcd.setCursor(col+1,2);
lcd.write((uint8_t)4);

lcd.setCursor(col+2,1);
lcd.write((uint8_t)5);
lcd.setCursor(col+2,2);
lcd.write((uint8_t)6);
lcd.setCursor(col+2,3);
lcd.write((uint8_t)7);

lcd.setCursor(col+7, 0);
lcd.printf("Joint");
lcd.setCursor(col+7, 1);
lcd.printf("Quantum");
lcd.setCursor(col+7, 2);
lcd.printf("Institute");
}


void setup(){

  SPI.begin();
  delay(10);  // necessary??
  lcd.begin();
  delay(100);
  
  Logo();
  delay(5000);
  lcd.clear();
  
  lcd.cursor();
  lcd.print("This is LCD test");

  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("overwrite");

  delay(1000);

  lcd.clear();
  lcd.print("printf example");
  lcd.setCursor(0, 1);
  lcd.printf("%d is a number", 10);
  delay(3000);
  lcd.clear();
}

void loop()
{
 
  //lcd.on();
  //lcd.backlight();
  //delay(2000);
  //lcd.noBacklight();
  //lcd.setCursor(5,0);
  //delay(3000);
  //lcd.moveCursorRight();
  //delay(3000);
  //lcd.printf("Target");
  //lcd.autoscroll();
  //delay(3000);
  //lcd.noBlink();
  //delay(3000);
  //lcd.printf("Target');
  //lcd.rightToLeft();
  //delay(3000);
  //lcd.noDisplay();
  //delay(2000);
  //lcd.display();
  //delay(3000);
  //lcd.clear();
  //delay(3000);
  //lcd.setCursor(3,3);
  //lcd.printf("Target!");
  //delay(2000);
  //lcd.setCursor(8, 3);
  //lcd.printf("T");
  //delay(2000);
  
}
