#include <SoftwareSerial.h>
#include "LoRa_E22.h"

SoftwareSerial loraSerial(10,11); // TX,Rx
void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
  
}

void loop() {
  if (loraSerial.available()>0){
    int sayac =0;
    Serial.print("Seri haberlesme: ");
    Serial.println(sayac);  
    sayac++;
    delay(1000);
  }
  delay(100);
}
