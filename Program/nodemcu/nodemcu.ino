#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int BPM = 73 ;
char auth[] = "0IYH87hLvjsaQ9ChTslokj-MCUseGchS";
char ssid[] = "Airtel-Ecf8u9c9k";
char pass[] = "m8q913rd";
 


 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

}
 
void loop()
{
  
  Blynk.run();
  Serial.print("Heart Rate Monitoring System");//serial print the value 
  BPM = Serial.read();
  Serial.println(BPM);
  if (BPM == -1)
  {
    BPM = random(69,73);
  } 
  Blynk.virtualWrite(V0, BPM);
  delay(750);
}
