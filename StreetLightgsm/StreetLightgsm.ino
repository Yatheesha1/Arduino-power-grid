#include <SoftwareSerial.h>
#include<String.h>
#include <AltSoftSerial.h>
#include <TinyGPS++.h>

String number1="+919686047061";
String number2="+917019244463";
String number3="+917259274461";
//String number3="+918848337736";

String numadmin="+918848337736";
String message="";
String num="";

String st="http://maps.google.com/?q=";
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
AltSoftSerial gpsSerial;//(RX 8, TX 9);

SoftwareSerial mySerial(2,3);//(Rx,Tx)

int relaypin = 4;//flow sensor pin
int pirpin=5;
int voltagepin=A0;
int value=0;
int pir=0;
int gpsflag=0;

int voltage=0;
int contiflag=0;
int k=0;
int flagtime=0;
//int syncpinr=6;
int syncpins=7;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  Serial.println(mySerial.readString());
  
  pinMode(voltagepin, INPUT);
  pinMode(relaypin, OUTPUT);
  
  //pinMode(syncpinr, INPUT);
  pinMode(syncpins, OUTPUT);
  
  //digitalWrite(syncpinr, LOW);
  digitalWrite(syncpins, LOW);
  pinMode(pirpin, INPUT);
  
  
  gpsSerial.begin(9600); 
}

void loop()
{
  if(flagtime==1)
  { 
    pir=digitalRead(pirpin);

    if(pir==1)
    {
      value=1;
      k=1;
      process(); 
    }
    if(pir==0 && k==1) 
    { 
      value=0;
      k=0;
      process();
    }
  }
  
  gsm();

  if(Serial.available())
   {
     value=Serial.parseInt();
     process();
   }
  
  voltage=analogRead(voltagepin);
  //Serial.print("    voltage:");
  //Serial.println(voltage);
  if(voltage<100 && contiflag==0 && value==1)
  { 
    Gpslocate();
    st="POWER FAILURE AT "+ st;
    contiflag=1;
    SendMessage(st,numadmin);
  }
  if(voltage>100)
     contiflag=0; 
   
}   
