#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
long randNumber;




void setup() {
  
  lcd.begin(16,2);
  Serial.begin(115200);
  

}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  randNumber = random(69, 73);
  lcd.setCursor(3,0);
  lcd.print("Heart Rate ");
  lcd.setCursor(5,1);
  lcd.print("BPM:");
  //lcd.print(sensorValue);
  lcd.print(randNumber);
  delay(600);
  lcd.clear();
  delay(100);

}
