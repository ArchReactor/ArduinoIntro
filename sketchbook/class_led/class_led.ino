int8_t pos = 0, dir = 1; // Position, direction of "eye"
long lastMillis = 0;

int8_t leds[] = {9,10,11};
#define NUMBER_OF_LEDS (sizeof(leds)/sizeof(int8_t))

void setup(){
  //start serial connection
  Serial.begin(115200);

  //configure LED outputs and turn them off
  for(int i=0; i < NUMBER_OF_LEDS; i++) {
    pinMode(leds[i], OUTPUT); 
    digitalWrite(leds[i], LOW);
  }
}

void loop(){
  if (lastMillis + 150 <= millis()) {
    pos += dir;
    if(pos == -2) {
      dir = -dir;
    } else if(pos == NUMBER_OF_LEDS+1) {
      dir = -dir;
    }
    for(int i=0; i < NUMBER_OF_LEDS; i++) {
      if(i==pos-1 || i==pos+1) {
        analogWrite(leds[i], 16);
      } else if(i==pos) {
        analogWrite(leds[i], 255);
      } else {
        digitalWrite(leds[i], LOW);
      }
    }
    lastMillis = millis();
  }
  
}



