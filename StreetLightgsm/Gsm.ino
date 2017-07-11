void gsm()
{
  if (mySerial.available())
  { 
    message="";
    num="";
    String msg=mySerial.readString();
    Serial.println(msg);
    num=msg.substring(9,22);
    Serial.print("Number:");   
    Serial.println(num);   
    if(num==number1 || num==number2 || num==number3) 
    {    
       message=msg.substring(51,msg.length()-2); 
       if(message=="ON")
       {
          value=1;
          SendMessage("LIGHT ON",num);
          Serial.println("LIGHT ON");
       }   
       if(message=="OFF")  
       { 
          value=0;
          SendMessage("LIGHT OFF",num);
          Serial.println("LIGHT OFF");
       }
       if(message=="OFF TIME")
       {
          flagtime=0;
          SendMessage("OFF TIME STARTED",num);
          Serial.println("OFF TIME STARTED");
          digitalWrite(syncpins,LOW);
       }
       if(message=="FULL TIME")  
       { 
          flagtime=2;    
          SendMessage("FULL TIME STARTED",num);
          Serial.println("FULL TIME STARTED");
          digitalWrite(syncpins,LOW);
       }
       if(message=="SAVING TIME")   
       {
          flagtime=1;   
          SendMessage("SAVING TIME STARTED",num);
          Serial.println("SAVING TIME STARTED");
          digitalWrite(syncpins,HIGH);
       }  
       process();  
       delay(1000);
    }   
  }
}

void SendMessage(String ms,String nu)
{
  mySerial.println("AT+CMGF=1\r\n"); //Sets the GSM Module in Text Mode
  delay(1000); // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\""+nu+"\"\r\n"); // Replace x with mobile number
  delay(1000);
  mySerial.println(ms);
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
