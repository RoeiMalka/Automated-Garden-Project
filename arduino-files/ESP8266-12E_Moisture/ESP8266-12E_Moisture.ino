/* ESP8266 Moisture Sensor
   This sketch uses an ESP8266 to read the analog signal from a moisture sensor. The data is then displayed
   using the serial console or a web browser. Based on the moisture reading, the ESP8266 will blink a RGB LED
   red, green or blue.
   
     Viewing the data via web browser by going to the ip address. In this sketch the address is
     http://192.168.1.221

      The browser data includes a Google Chart to visually illustrate the moisture reading as a guage.

   ///////////////////////////////////////
   Arduino IDE Setup
   File:
      Preferences
        Add the following link to the "Additional Boards Manager URLs" field: 
        http://arduino.esp8266.com/stable/package_esp8266com_index.json
   Tools:
      board: NodeMCU 1.0 (ESP-12 Module)
      programmer: USBtinyISP

      
  ///////////////////////////////
*/
#include <ESP8266WiFi.h>

const char* WIFI_SSID = "malka_home";
const char* WIFI_PASS = "mg2jBCNe";

int analogValue;
int nHumidity;

String JSONMessage = "{\"SensorType\": \"SoilMoisture\", \"Value\": ";
String jsCode;

WiFiServer server(80);

void javascriptContent(String json, int value) {
  // jQuery library
  jsCode = "<script src=\"http://code.jquery.com/jquery-3.2.1.min.js\" integrity=\"sha256-hwg4gsxgFZhOsEEamdOYGBf13FyQuiTwlAQgxVSNgt4=\" crossorigin=\"anonymous\"></script>\n";

  // AJAX post request to server.
  jsCode += "<script>\n";
  jsCode += "$.ajax({\n";
  jsCode += "url: \"http://10.0.0.25/add\",\n";
  jsCode += "type: \"POST\",\n";
  jsCode += "data: {humidity : "; 
  jsCode += value; 
  jsCode += "}\n";
  jsCode += "\n";
  jsCode += "});\n";
  jsCode += "</script>\n";

  Serial.println(jsCode);
}

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Set the ip address of the webserver
  // WiFi.config(WebServerIP, Gatway, Subnet)
  // or comment out the line below and DHCP will be used to obtain an IP address
  // which will be displayed via the serial console

  // WiFi.config(IPAddress(192, 168, 1, 221), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));

  // connect to WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  
}

void loop() {

  analogValue = analogRead(A0); // read the analog signal

  // Convert the analog signal to percentages.
  analogValue = constrain(analogValue, 300, 1023);
  nHumidity = map(analogValue, 300, 1023, 100, 0);

  javascriptContent(JSONMessage, nHumidity);
  delay(15000);
/*
  Serial.print(JSONMessage);
  Serial.print(nHumidity);
  Serial.println("}");
  delay(500);
  
  // check to for any web server requests. ie - browser requesting a page from the webserver
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println(""); //  do not forget this one
  client.print(JSONMessage);
  client.print(nHumidity);
  client.println("}");
*/
}

