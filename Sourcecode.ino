#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define R1 5      // D1
#define R2 4      // D2
#define R3 3      // D3
#define R4 2      // D5
#define R5 14     // D6
#define R6 12     // D4


char auth[] = "iStW3X5UiMr3ffAeNwPO-OhmN_r7rASH"; // the auth code in blink
char ssid[] = "Y2kz"; // username or ssid of your WI-FI
char pass[] = "Y2kz1234"; // password of your Wi-Fi

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(R1,OUTPUT); //extend these to D8 if you are using a 8 pin relay 
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(R5,OUTPUT);
  pinMode(R6,OUTPUT);

  digitalWrite(R1,LOW); // Make it high if you want everything to Turn on
  digitalWrite(R2,LOW); // in case of a power cut
  digitalWrite(R3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(R5,LOW);
  digitalWrite(R6,HIGH);
  
  
  

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
