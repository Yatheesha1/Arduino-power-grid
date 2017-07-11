#include <SoftwareSerial.h>
#include<String.h>
#include <SPI.h>
#include <Ethernet.h>
#include <AltSoftSerial.h>
#include <TinyGPS++.h>

String number1="+919343616936";
String number2="+917019244463";
String number3="+918848337736";

String numadmin="+918848337736";
String message="";
String num="";

String st="http://maps.google.com/?q=";
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
AltSoftSerial gpsSerial;//(RX 8, TX 9);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };//MAC address

IPAddress ip(192,168,137,20);//
EthernetServer server(80);

SoftwareSerial mySerial(2,3);//(Rx,Tx)

int relaypin = 4;//flow sensor pin
int pirpin=6;
int currentpin=A0;
int voltagepin=A1;
int value=0;
int gpsflag=0;

const char *state[]={"LIGHT OFF","LIGHT ON"};

int voltage=0;
int pir=0;
int current=0;
int flag=0;
int loopflag=0;
int contiflag=0;
int k=0;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  Serial.println(mySerial.readString());
  Ethernet.begin(mac, ip);
  server.begin();
  
  pinMode(pirpin, INPUT);
  pinMode(currentpin, INPUT);
  pinMode(voltagepin, INPUT);
  pinMode(relaypin, OUTPUT);
  
  gpsSerial.begin(9600); 
}

void loop()
{
   Read();
   serial();
   //ether();
   gsm();
   
}   
