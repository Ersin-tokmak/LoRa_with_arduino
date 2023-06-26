#include <SoftwareSerial.h>
SoftwareSerial FixSerial(0,1);
 
#define M0 6
#define M1 7
byte upperByte, lowerByte;
int newInt=0;
 
void setup() {
  Serial.begin(9600);
   
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  digitalWrite(M0, LOW);
  digitalWrite(M1, LOW);
   
  FixSerial.begin(9600);
}
 
void loop() {
  if (FixSerial.available() > 1) {
    upperByte = FixSerial.read();
    lowerByte = FixSerial.read();
 
    newInt = (upperByte << 8) + lowerByte;
    Serial.print("Sayi= ");
    Serial.println(newInt);
  }
}
 
