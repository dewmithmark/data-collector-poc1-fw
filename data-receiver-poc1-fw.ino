#include <SPI.h>
#include "LoRa.h" 

#define ss 15
#define rst 16
#define dio0 2

int counter = 0;
float t = 0;
int h = 0;
 
void setup() 
{
  Serial.begin(9600); 
  
  while (!Serial);
  Serial.println("LoRa Receiver");
  LoRa.setPins(ss, rst, dio0);
  
    if (!LoRa.begin(433E6)) 
    {
      Serial.println("Starting LoRa failed!");
      delay(100);
      while (1);
    }  
}

void loop() 
{
  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) 
  {
    // received a paket
    Serial.println("Received packet '");
    // read packet
    Serial.println("\n");
    while (LoRa.available()) 
    {
      char incoming = (char)LoRa.read();
      if (incoming == 'c')
      {
        Serial.print("\r");
      }
      else
      {
        Serial.print(incoming);
      }
    }
  }  
}
