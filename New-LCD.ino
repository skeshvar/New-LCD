#include <SPI.h>
#include "LCD.h"

#define LCD_RST 0
#define LCD_RS  1
#define LCD_CS  10
/*
This is just examples.
*/

LCD_SSD1311 lcd( LCD_CS );

void setup(){
  SPI.begin();
  delay(10);  // necessary??

  lcd.begin();
  delay(100);

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
}

void loop(){
  
  lcd.clear();
  //lcd.off();
  delay(2000);
  lcd.createChar(uint8_t 0x80 , "Hello");
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
