void serial()
{
   if(Serial.available())
   {
     value=Serial.parseInt();
     process();
   }
}   
