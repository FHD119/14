#include "dht.h"
#define dht_apin A0 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
dht DHT;
 
void setup(){
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  lcd.init();                      
  lcd.backlight();
  delay(1000);
}
 
void loop(){
 
    DHT.read11(dht_apin);
     lcd.setCursor(0,0);
     lcd.print("Temp= ");
     lcd.print(DHT.temperature);
     lcd.print(" C");
     lcd.setCursor(0,1);
     lcd.print("Humidity= ");
     lcd.print(DHT.humidity);
     lcd.print("%");
   
   if ( DHT.temperature > 24.00) {
    // turn LED on
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
  } else {
    // turn LED off
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
}
 delay(2000);
}
