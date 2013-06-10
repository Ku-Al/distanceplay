
#include "Ultrasonic.h"
#include <LiquidCrystal.h>

Ultrasonic ultrasonic(12, 13);

void setup()
{
  Serial.begin(9600); 
 // lcd.begin(16, 2);
  //lcd.print("testing...");
}

void loop()
{
 // lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print(ultrasonic.Ranging(CM));
//  lcd.print("cm");
//    int ss=ultrasonic.Ranging(CM);
    int ss=map(ultrasonic.Ranging(CM),1,200,1,10);
    Serial.print(ss, DEC);
   // Serial.print("cm");
  Serial.print("\n");
  delay(200);
}
