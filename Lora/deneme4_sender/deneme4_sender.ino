#include <SoftwareSerial.h>
#include "EBYTE22.h"

#define PIN_TX 2
#define PIN_RX 3
#define PIN_M0 4
#define PIN_M1 5
#define PIN_AX 6

SoftwareSerial E22Serial(PIN_TX, PIN_RX, false);

EBYTE22 E22(&E22Serial, PIN_M0, PIN_M1,PIN_AX);

byte testByte=123;
String testString = "Test";
struct myStruct{
  int days = 365;
  float pi= 3.14;
  long lightSpeed = 299792458;
  
} testStruct;

void setup() {
  Serial.begin(9600);
  E22Serial.begin(9600);
  Serial.println("Gonderim Baslıyor...");
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
  if(E22.getBusy())
  {
    E22.completeTask(5000);
  }
E22.sendStruct(&testStruct,sizeof(testStruct));
E22.sendByte(testByte);
E22Serial.print(testString);
E22.flush();
delay(5000);

}
