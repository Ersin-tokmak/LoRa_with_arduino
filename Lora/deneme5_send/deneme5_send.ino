
#include <SoftwareSerial.h>
SoftwareSerial FixSerial(0,1);
 
#define M0 7
#define M1 6
 
void setup() {
  Serial.begin(9600);
 
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  digitalWrite(M0, LOW);
  digitalWrite(M1, LOW);
 
  FixSerial.begin(9600);
}
 
void loop() {
  FixSerial.write((byte)0x00); //Alıcı Adresi HIGH
  FixSerial.write(0x3f);       //Alıcı Adresi LOW
  FixSerial.write(0x17);       //Alıcı Kanalı =0x17=23    (410M+23=433 MHz)
 
  intGonder(12345); // Bu Sayıyı Göndereceğiz ->
  delay(1000);
}
 
void intGonder(int sayi) {
  FixSerial.write(highByte (sayi));
  FixSerial.write(lowByte (sayi));
}
