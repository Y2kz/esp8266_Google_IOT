
// Constants set pin numbers:

//Input
const int input1 = 2;     // The number of the Input pins
/*
  const int input2 = 2;
  const int input3 = 2;
  const int input4 = 2;
  const int input5 = 2;
*/

//Output
const int output1 =  13;      // The number of the Output pin
/*
  const int output2 =  13;
  const int output3 =  13;
  const int output4 =  13;
  const int output5 =  13;
*/

// variables will change:
int inputState1 = 0;         // variable for reading input pin status
/*
  int inputState2 = 0;
  int inputState3 = 0;
  int inputState4 = 0;
  int inputState5 = 0;
*/

void setup() {


  // initialize the output pin as an output:
  pinMode(output1, OUTPUT);
  /*
    pinMode(output2, OUTPUT);
    pinMode(output3, OUTPUT);
    pinMode(output4, OUTPUT);
    pinMode(output5, OUTPUT);
  */


  // initialize the input pin as an input:
  pinMode(input1, INPUT);
  /*
    pinMode(input2, INPUT);
    pinMode(input3, INPUT);
    pinMode(input4, INPUT);
    pinMode(input5, INPUT);
  */
}

void loop() {
  // read the state input state value:
  inputState1 = digitalRead(input1);
  /*
    inputState2 = digitalRead(input2);
    inputState3 = digitalRead(input3);
    inputState4 = digitalRead(input4);
    inputState5 = digitalRead(input5);
  */

  // check if input is HIGH. If it is, the inputState1 is HIGH:
  //PIN 1
  if (inputState1 == HIGH) {
    // turn Output on:
    digitalWrite(output1, HIGH);
  } else {
    // turn Output off:
    digitalWrite(output1, LOW);
  }
/*
  //PIN 2
  if (inputState2 == HIGH) {
    // turn Output on:
    digitalWrite(output1, HIGH);
  } else {
    // turn Output off:
    digitalWrite(output1, LOW);
  }

  //PIN 3
  if (inputState3 == HIGH) {
    // turn Output on:
    digitalWrite(output3, HIGH);
  } else {
    // turn Output off:
    digitalWrite(output3, LOW);
  }

  //PIN 4
  if (inputState4 == HIGH) {
    // turn Output on:
    digitalWrite(output4, HIGH);
  } else {
    // turn Output off:
    digitalWrite(output4, LOW);
  }

  //PIN 5
  if (inputState5 == HIGH) {
    // turn Output on:
    digitalWrite(output5, HIGH);
  } else {
    // turn Output off:
    digitalWrite(output5, LOW);
  }
*/
}
