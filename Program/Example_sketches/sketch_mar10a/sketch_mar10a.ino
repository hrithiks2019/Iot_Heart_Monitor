#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h> 
#include<LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


const int PulseWire = 0; 
const int LED13 = 13; 
int Threshold = 250; 

PulseSensorPlayground pulseSensor; 


void setup() 
{

  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.home();
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13); 
  pulseSensor.setThreshold(Threshold);
  if (pulseSensor.begin()) 
	{
		Serial.println("We created a pulseSensor Object !");
		lcd.setCursor(0,0);
		lcd.print(" Heart Rate Monitor");
	}
}

void loop() 
{

  int myBPM = pulseSensor.getBeatsPerMinute(); 
  if (pulseSensor.sawStartOfBeat()) 
	{ 
		Serial.print("BPM: "); 
		Serial.println(myBPM); 
		lcd.setCursor(0,0);
		lcd.print("HeartBeat Happened !"); 
		lcd.setCursor(5,1);
		lcd.print("BPM: "); 
		Serial.write(myBPM);
		lcd.print(myBPM);
		lcd.clear();
	}
  delay(20); 
}
