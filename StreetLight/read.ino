void Read()
{
	pir=digitalRead(pirpin);
  current=analogRead(currentpin);
  voltage=analogRead(voltagepin);
 // Serial.print("currnt:");
 // Serial.print(current);
 Serial.print("    voltage:");
 Serial.println(voltage);

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
  
  if(voltage>700 && loopflag==0)
  { 
    Gpslocate();
    loopflag=1;
    st="LOOPING AT "+ st;
    SendMessage(st,numadmin);
  }
  if(voltage<400)
     loopflag=0;

  if(current==0 && contiflag==0)
  { 
    Gpslocate();
    st="POWER FAILURE AT "+ st;
    contiflag=1;
    SendMessage(st,numadmin);
  }
  if(current>0)
     contiflag=0; 
}
