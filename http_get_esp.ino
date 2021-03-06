#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "SSID";
const char* password = "SENHA";

//const char* ssid = "Raspberry";
//const char* password = "Ankara006";
String payload = "";
void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://jsonplaceholder.typicode.com/users/1");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
       payload += http.getString();   //Get the request response payload
      // httpCode =http.GET();

    }

    http.end();   //Close connection
 
  }
         Serial.println(payload);                     //Print the response payload
  payload = "";
  delay(10000);    //Send a request every 30 seconds
 
}
