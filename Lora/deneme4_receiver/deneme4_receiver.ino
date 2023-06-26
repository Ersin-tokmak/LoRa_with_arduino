#include <SoftwareSerial.h>
#include "EBYTE22.h"

#define PIN_TX 2
#define PIN_RX 3
#define PIN_M0 4
#define PIN_M1 5
#define PIN_AX 6

SoftwareSerial E22Serial(PIN_TX, PIN_RX, false);
EBYTE22 E22(&E22Serial, PIN_M0, PIN_M1,PIN_AX);
byte testByte;
String testString;
struct myStruct{
  int days;
  float pi;
  long lightSpeed ;
  
} testStruct;


void setup() {
  Serial.begin(9600);
  E22Serial.begin(9600);
  Serial.println("Baslıyor...");
  delay(200);
  if(E22.init())
  {
    Serial.println("init OK");
  }
  else
  {
    Serial.println("init error");
  }
  
}
void loop() {
  if(E22.available()){
    E22.getStruct(&testStruct, sizeof(testStruct));
    testByte = E22.getByte();
    testString = E22Serial.readString();

    Serial.println("---------");
    Serial.println("DENEME4");
    Serial.println("Gün sayisi: " + String(testStruct.days));
    Serial.println("Pi sayisi: " + String (testStruct.pi));
    Serial.println("Isik hizi: " + String (testStruct.lightSpeed));
    Serial.println("----------");
    Serial.println("Test Bayti: " + String(testByte));
    Serial.println("Test String: " + testString);
    
    
  }
  delay(1000);
  

}
