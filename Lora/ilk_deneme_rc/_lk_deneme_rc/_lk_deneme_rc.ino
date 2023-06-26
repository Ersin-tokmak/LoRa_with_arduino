#include <SoftwareSerial.h>

SoftwareSerial FixSerial(10,11);
char rc;


void setup() {
  Serial.begin(9600);
  FixSerial.begin(9600);
}

void loop() {
  while(FixSerial.available())
  {
    rc = FixSerial.read();
    Serial.print(rc);

  }
}
