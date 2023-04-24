#include <SPI.h>
#include "LoRa.h" 

#define ss 15
#define rst 16
#define dio0 2

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

  Serial.println("Rain_status,temperature,humidity");
}

void loop() 
{
  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) 
  {
    // received a paket
   
     while (LoRa.available()) 
    {
      char incoming = (char)LoRa.read();
      if (incoming == 'c')
      {
        Serial.print("\r\n");
      }
      else
      {
        Serial.print(incoming);
      }
    }
  }  
}
