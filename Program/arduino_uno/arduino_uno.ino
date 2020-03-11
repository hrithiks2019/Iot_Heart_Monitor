#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

long BPM;
byte heart[] = 
{
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};


void setup() {
  
  lcd.begin(16,2);
  Serial.begin(115200);
  lcd.createChar(0, heart);
  lcd.home();
}

void loop() {
  int sensorValue = analogRead(A0);
  BPM = random(69, 73);
  Serial.write(int(BPM));
  lcd.setCursor(3,0);
  lcd.print("Heart Rate ");
  lcd.setCursor(3,1);
  lcd.write((byte)0);
  lcd.print(" BPM:");
  lcd.print(BPM);
  lcd.print(" ");
  lcd.write((byte)0);
  delay(600);
  lcd.clear();
  delay(100);
}
