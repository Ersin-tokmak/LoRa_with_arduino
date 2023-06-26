#include "LoRa_E22.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1); // Arduino RX <-- e22 TX, Arduino TX --> e22 RX
LoRa_E22 e22ttl(&mySerial);
 
struct Signal {
  char type[15];
  byte temp[4];
} data;
 
void setup() {
  Serial.begin(9600);
  e22ttl.begin();
  delay(500);
}
 
void loop() {
  while (e22ttl.available()  > 1) {
 
    // Gelen mesaj okunuyor
    ResponseStructContainer rsc = e22ttl.receiveMessage(sizeof(Signal));
    struct Signal data = *(Signal*) rsc.data;
    Serial.print("Gelen Messaj: ");
    Serial.println(data.type);
    rsc.close();
 
    //Gönderilecek paket veri hazırlanıyor
    struct Signal  {
      char type[15] = "Oda ";
      byte temp[4];
    } data2;
 
    *(float*)(data2.temp) = 19.2;
 
 
    ResponseStatus rs = e22ttl.sendFixedMessage(0, 63, 23, &data2, sizeof(Signal));
    Serial.println(rs.getResponseDescription());
 
  }
 
}
