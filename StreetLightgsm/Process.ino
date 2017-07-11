void process()
{
  if(flagtime==1)
  {
   if(value==1)
     digitalWrite(relaypin,HIGH);
   if(value==0)
     digitalWrite(relaypin,LOW); 
  }
  if(flagtime==0)
    digitalWrite(relaypin,LOW); 
  if(flagtime==2)  
    digitalWrite(relaypin,HIGH);
    
}
