//define and 8bit variable to hold the last button state, default is HIGH 
uint8_t buttonState = HIGH;

//define and 8bit variable to hold the current LED, default is the one on pin 9 
uint8_t curLED = 9;

void setup(){
  //start serial connection
  Serial.begin(115200);

  //configure pin2 as an input and enable the internal pull-up resistor to amke default HIGH
  pinMode(2, INPUT_PULLUP);

  //configure LED outputs and turn them off
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
}

void loop(){
  //read button and see if it has changed
  if(digitalRead(2) != buttonState) {
    delay(5); //wait a little just to be sure
    //check button again
    if(digitalRead(2) != buttonState) {
      buttonState = digitalRead(2); //record for later
      //if it's changed dnad it's HIGH...
      if (buttonState == HIGH) {
        if(curLED == 9) {
          curLED = 10;
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW);
        } else if (curLED == 10) {
          curLED = 11;
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, HIGH);
        } else {
          curLED = 9;
          digitalWrite(9, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
        }
      }
    }
  }
}



