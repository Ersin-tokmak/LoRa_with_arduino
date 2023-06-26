#include <SoftwareSerial.h>

SoftwareSerial FixSerial(10,11);

String a="ERSIN TOKMAK";
  

void setup() {
  Serial.begin(9600);
  FixSerial.begin(9600);
}

void loop() {
  FixSerial.write((byte)0x00);  //Alıcı adresi hıgh
  FixSerial.write(0x41);          //Alıcı adresi low
  FixSerial.write(0x17); //Alıcı kanalı 0x17=23  (410M+23=433 Mhz)
  FixSerial.write(0x11);
  FixSerial.write("\n");
  FixSerial.println("Selam");
  FixSerial.println(a);
  delay(500);
  
}
