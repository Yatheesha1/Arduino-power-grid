void process()
{
  if(value==1)
    digitalWrite(relaypin,HIGH);
  if(value==0)
    digitalWrite(relaypin,LOW); 
  if(value!=flag)  
  { 
    Serial.println(state[value]);   
    flag=value;
  }    
}
