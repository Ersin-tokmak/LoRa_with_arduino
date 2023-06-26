void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int kl=0;kl<7;kl++)
  {
    FixSerial.write("\n");
    FixSerial.write("Degerler: ");
    
    FixSerial.write(degerler[kl]);
  }
  // put your main code here, to run repeatedly:


}
