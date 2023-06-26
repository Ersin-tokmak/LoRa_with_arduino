#include "Arduino.h"
#include "LoRa_E22.h"
 
LoRa_E22 e22ttl(3, 2); // Arduino RX --> e22 TX - Arduino TX --> e22 RX
 
void setup() {
  Serial.begin(9600);
  delay(500);
 
  Serial.println("Hi, I'm going to send message!");
 
  // Startup all pins and UART
  e22ttl.begin();
 
  // Send message
  ResponseStatus rs = e22ttl.sendMessage("Hello, world?");
  // Check If there is some problem of successfully send
  Serial.println(rs.getResponseDescription());
}
 
void loop() {
    // If something available
  if (e22ttl.available()>1) {
      // read the String message
    ResponseContainer rc = e22ttl.receiveMessage();
    // Is something goes wrong print error
    if (rc.status.code!=1){
        Serial.println(rc.status.getResponseDescription());
    }else{
        // Print the data received
        Serial.println(rc.data);
    }
  }
  if (Serial.available()) {
      String input = Serial.readString();
      e22ttl.sendMessage(input);
  }
}
