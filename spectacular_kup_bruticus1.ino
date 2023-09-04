#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38, 16, 2);
byte customChar[8] = {
  B11000,
  B11100,
  B11110,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000
};
bool upbutton=5;
bool downbutton=6;
int menue;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, customChar);
  lcd.home();
 lcd.write(0);
  pinMode(5,0);
  pinMode(6,0);lcd.clear();
    lcd.write(0);
    lcd.print(" Select Program");
    lcd.setCursor(0,1);
     lcd.print(" Settings");
  
  
}
void updateMenue(){
  switch(menue){
    case 0:
    lcd.clear();
    lcd.write(0);
    lcd.print(" Select Program");
    lcd.setCursor(0,1);
     lcd.print(" Settings");
     break;
       case 1:
    lcd.clear();
    lcd.print("Select Program");
    lcd.setCursor(0,1);
    lcd.write(0);
    lcd.print(" Settings");
     break;
       case 2:
    lcd.clear();
    lcd.print(" Settings");
    lcd.setCursor(0,1);
    lcd.write(0);
    lcd.print(" Power Saving");
     break;
       case 3:
    lcd.clear();
    lcd.print(" Power Saving");
    lcd.setCursor(0,1);
    lcd.write(0);
    lcd.print(" Shut down");
     break;
    }
  }
void loop() { 
  if(digitalRead(5)==1){
    menue++;
    updateMenue();
    }
     if(digitalRead(6)==1){
    menue--;
    updateMenue();
    }
}