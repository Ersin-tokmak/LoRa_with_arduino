#include <SoftwareSerial.h>
#include "LoRa_E22.h"

SoftwareSerial loraSerial(10,11); // TX,Rx
void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
  
}

void loop() {
  if (Serial.available()>0){
    char msg = Serial.readString();
    loraSerial.print(msg);
    Serial.println(msg);
  }
}
