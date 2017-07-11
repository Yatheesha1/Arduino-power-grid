void process()
{
  if(flagtime==1)
  {
    if(value==1)
    {
      digitalWrite(relaypin,HIGH);
      Serial.println("LIGHT ON");
    }
    if(value==0)
    {
      digitalWrite(relaypin,LOW);
      Serial.println("LIGHT OFF");
    }
  } 
  if(flagtime==0)
  {
    digitalWrite(relaypin,LOW);
  }
  if(flagtime==2)
  {
    digitalWrite(relaypin,HIGH); 
  }
}
