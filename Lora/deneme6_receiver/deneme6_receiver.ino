#include "LoRa_E22.h"
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(0,1);
 
/*
   Pinler     Arduino uno    Lora E32 433T20d
                  0                 3
                  1                 4
*/
 
LoRa_E22 e22ttl(&mySerial);
 
struct Signal {
  char type[15] = "Fixaj.com";
  byte temp[4];
} data;
 
 
void setup() {
  Serial.begin(9600);
  e22ttl.begin();
  delay(500);
}
 
void loop() {
 
  ResponseStatus rs = e22ttl.sendFixedMessage(0, 44, 23, &data, sizeof(Signal));
  Serial.println(rs.getResponseDescription());
 
  delay(2000);
 
  while (e22ttl.available()  > 1) {
    ResponseStructContainer rsc = e22ttl.receiveMessage(sizeof(Signal));
    struct Signal data = *(Signal*) rsc.data;
    Serial.print("Yer: ");
    Serial.println(data.type);
    Serial.print("Ortam Sıcaklığı: ");
    Serial.println(*(float*)(data.temp));
    rsc.close();
  }
}
