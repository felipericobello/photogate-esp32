/*
  SETUPCODE:
    // if your web page or XML are large, you may not get a call back from the web page
    // and the ESP will think something has locked up and reboot the ESP
    // not sure I like this feature, actually I kinda hate it
    // disable watch dog timer 0
    disableCore0WDT();

    #ifdef USE_INTRANET
    WiFi.begin(LOCAL_SSID, LOCAL_PASS);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.print("IP address: "); Serial.println(WiFi.localIP());
    ActualIP = WiFi.localIP();
    #endif

    #ifndef USE_INTRANET
    WiFi.softAP(AP_SSID, AP_PASS);
    delay(100);
    WiFi.softAPConfig(PageIP, Gateway, Subnet);
    delay(100);
    ActualIP = WiFi.softAPIP();
    Serial.print("IP address: "); Serial.println(ActualIP);
    #endif

    PrintWifiStatus();

    // these calls will handle data coming back from your web page
    // this one is a page request, upon ESP getting / string the web page will be sent
    //Server.on("/", SendWebsite);

    // upon esp getting /XML string, ESP will build and send the XML, this is how we refresh
    // just parts of the web page
    //Server.on("/xml", SendXML);

    Server.begin();


//Medidas provisórias: 

/*
void SendWebsite() {

  Serial.println("sending web page");
  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  Server.send(200, "text/html", PAGE_MAIN);

}
*/

/*
void SendXML() {

  // Serial.println("sending xml");

  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

  strcat(XML, "</Data>\n");
  // wanna see what the XML code looks like?
  // actually print it to the serial monitor and use some text editor to get the size
  // then pad and adjust char XML[2048]; above
  Serial.println(XML);

  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  Server.send(200, "text/xml", XML);
}

void PrintWifiStatus() {

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  Ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(Ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("Open http://");
  Serial.println(Ip);
}

*/
