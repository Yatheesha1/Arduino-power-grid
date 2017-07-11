void ether()
{
  EthernetClient client;
  String readString;
  client = server.available();
  if (client) 
  {
    while (client.connected()) 
    {   
      if (client.available()) 
      {
         char c = client.read(); 
         //read char by char HTTP request
         if (readString.length() < 100) 
         {
          //store characters to string
          readString += c;
         }   
         //if HTTP request has ended
         if (c == '\n') 
         {              
           client.println("HTTP/1.1 200 OK"); //send new page
           client.println("Content-Type: text/html");
           client.println();  
              
           client.println("<HTML>");
           
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
           client.println("<TITLE>Arduino Project</TITLE>");
           client.println("</HEAD>");
           
           client.println("<BODY>");  
                  
           client.println("<br/>");  
           client.println("<H2>IOT BASED AUTOMATIC SWITCHING AND FAULT DETECTION</H2>");
                              
           client.println("<br />");
           client.println("<br />");  
           client.println("<a href=\"/?button1on\"\">Turn On Light</a>");
           client.println("<a href=\"/?button1off\"\">Turn Off Light</a><br />");   
           client.println("<br />");    
           
           client.println("</BODY>");
           
           client.println("</HTML>");
     
           //delay(1);
           //stopping client
           client.stop();
           //controls the Arduino if you press the buttons
           
           if (readString.indexOf("?button1on") >0)
               value=1;
           if (readString.indexOf("?button1off") >0)
               value=0;   
           process();                  
         }  
      } 
    }     
    readString="";            
  }
}

