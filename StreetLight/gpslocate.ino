void Gpslocate()
{ 
  while (gpsSerial.available())
  {
    if (gps.encode(gpsSerial.read()))
    {
      Serial.print(F("Location: ")); 
      String st="http://maps.google.com/?q=";
      String lati,langi;
      if (gps.location.isValid())
      {
        lati=String(gps.location.lat(), 6);
        langi=String(gps.location.lng(), 6);
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
        st=st+lati+","+langi;
      }
      else
      {
        Serial.print(F("INVALID"));
      }
      Serial.print("    ");
      Serial.println(st);
      gpsflag=0;
      break; 
    }
    
  }    

  if (millis() > 5000 && gps.charsProcessed() < 10 && gpsflag==0)
  {
    Serial.println(F("No GPS detected: check wiring."));
    gpsflag=1;
  }
  
}
