//define and 8bit variable to hold the last button state, default is HIGH 
uint8_t buttonState = HIGH;

//define and 8bit variable to hold the LED state, default is LOW 
uint8_t ledState = LOW;

void setup(){
  //start serial connection
  Serial.begin(115200);

  //configure pin2 as an input and enable the internal pull-up resistor to amke default HIGH
  pinMode(2, INPUT_PULLUP);

  //configure LED output
  pinMode(13, OUTPUT); 
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
        if(ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
        digitalWrite(13, ledState);
      }
    }
  }
}



