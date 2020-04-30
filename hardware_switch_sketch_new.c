#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*#include <SPI.h>
  #include <Ethernet.h>
  #include <BlynkSimpleEthernet.h>
*/
// You should get Auth Token in the Blynk App.

char auth[] = "1PjSTNQjqc_GER_zK6Feo41QJY6yPqXT";
char ssid[] = "Y2kz";
char pass[] = "Y2kz1234";

// Set your LED and physical button pins here
const int ledPin1 = 16;
const int ledPin2 = 5;
const int ledPin3 = 4;
const int ledPin4 = 0;
const int ledPin5 = 2;

const int btnPin1 = 14 ;
const int btnPin2 = 12 ;
const int btnPin3 = 13 ;
const int btnPin4 = 15 ;
const int btnPin5 = 3 ;

BlynkTimer timer;
void checkPhysicalButton();

int ledState1 = LOW;
int btnState1 = HIGH;

int ledState2 = LOW;
int btnState2 = HIGH;

int ledState3 = LOW;
int btnState3 = HIGH;

int ledState4 = LOW;
int btnState4 = HIGH;

int ledState5 = LOW;
int btnState5 = HIGH;

// Every time we connect to the cloud...
BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);

  // Alternatively, you could override server state using:
  //Blynk.virtualWrite(V2, ledState);
}

// When App button is pushed - switch the state
BLYNK_WRITE(V1) {
  ledState1 = param.asInt();
  digitalWrite(ledPin1, ledState1);
}

BLYNK_WRITE(V2) {
  ledState2 = param.asInt();
  digitalWrite(ledPin2, ledState2);
}

BLYNK_WRITE(V3) {
  ledState3 = param.asInt();
  digitalWrite(ledPin3, ledState3);
}

BLYNK_WRITE(V4) {
  ledState4 = param.asInt();
  digitalWrite(ledPin4, ledState4);
}

BLYNK_WRITE(V5) {
  ledState5 = param.asInt();
  digitalWrite(ledPin5, ledState5);
}

void checkPhysicalButton()
{
  //1
  if (digitalRead(btnPin1) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState1 != LOW) {

      // Toggle LED state
      ledState1 = !ledState1;
      digitalWrite(ledPin1, ledState1);

      // Update Button Widget
      Blynk.virtualWrite(V1, ledState1);
    }
    btnState1 = LOW;
  } else {
    btnState1 = HIGH;
  }


  //2
  if (digitalRead(btnPin2) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState2 != LOW) {

      // Toggle LED state
      ledState2 = !ledState2;
      digitalWrite(ledPin2, ledState2);

      // Update Button Widget
      Blynk.virtualWrite(V2, ledState2);
    }
    btnState2 = LOW;
  } else {
    btnState2 = HIGH;
  }




  //3
  if (digitalRead(btnPin3) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState3 != LOW) {

      // Toggle LED state
      ledState3 = !ledState3;
      digitalWrite(ledPin3, ledState3);

      // Update Button Widget
      Blynk.virtualWrite(V3, ledState3);
    }
    btnState3 = LOW;
  } else {
    btnState3 = HIGH;
  }


  //4
  if (digitalRead(btnPin4) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState4 != LOW) {

      // Toggle LED state
      ledState4 = !ledState4;
      digitalWrite(ledPin4, ledState4);

      // Update Button Widget
      Blynk.virtualWrite(V4, ledState4);
    }
    btnState4 = LOW;
  } else {
    btnState4 = HIGH;
  }


  //5
  if (digitalRead(btnPin5) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState5 != LOW) {

      // Toggle LED state
      ledState5 = !ledState5;
      digitalWrite(ledPin5, ledState5);

      // Update Button Widget
      Blynk.virtualWrite(V5, ledState5);
    }
    btnState5 = LOW;
  } else {
    btnState5 = HIGH;
  }


}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  pinMode(btnPin1, INPUT_PULLUP);
  pinMode(btnPin2, INPUT_PULLUP);
  pinMode(btnPin3, INPUT_PULLUP);
  pinMode(btnPin4, INPUT_PULLUP);
  pinMode(btnPin5, INPUT_PULLUP);

  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
  digitalWrite(ledPin3, ledState3);
  digitalWrite(ledPin4, ledState4);
  digitalWrite(ledPin5, ledState5);



  // Setup a function to be called every 100 ms
  timer.setInterval(100L, checkPhysicalButton);
}



void loop()
{
  Blynk.run();
  timer.run();
}
