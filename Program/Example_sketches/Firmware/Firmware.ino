
int PulseSensorPurplePin = A0; // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = D4; // The on-board Arduion LED
int Buzzer=12;

int Signal; // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 519 ; // Determine which Signal to "count as a beat", and which to ingore.


// The SetUp Function:
void setup() {
pinMode(Buzzer,OUTPUT);
pinMode(LED13,OUTPUT); // pin that will blink to your heartbeat!
Serial.begin(9600); // Set's up Serial Communication at certain speed.

}

// The Main Loop Function
void loop() {

Signal = analogRead(PulseSensorPurplePin); // Read the PulseSensor's value.
// Assign this value to the "Signal" variable.

Serial.println(Signal); // Send the Signal value to Serial Plotter.


if(Signal > Threshold ){ // If the signal is above "519", then "turn-on" Arduino's on-Board LED.
digitalWrite(LED13,HIGH);
tone(Buzzer,1000);
delay(100);
} else {
digitalWrite(LED13,LOW); // Else, the sigal must be below "519", so "turn-off" this LED.
noTone(Buzzer);
}


delay(10);


}
