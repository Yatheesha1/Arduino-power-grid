#include<String.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };//MAC address

IPAddress ip(192,168,137,20);//
EthernetServer server(80);

int relaypin = 4;//flow sensor pin
int pirpin=5;
int pir=0;
int value=0;
int flag=0;
int k=0;
int flagtime=0;

void setup()
{
  pinMode(pirpin, INPUT);
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(relaypin, OUTPUT);
}

void loop()
{
  ether();    
}   
