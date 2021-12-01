#include <rpcWiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <DHT.h>
#include <ArduinoJson.h>


#include "config.h"

//Create a wifi object and a pubsub object using the wifi object
WiFiClient wioTerminalClient;
PubSubClient client( wioTerminalClient );

//Prototypes for function defined at the bottom of this doucment
void connectWifi( void );




void  setup()
{
    //Begin serial
    Serial.begin(9600);
    while (!Serial)
        delay(1000);
    Serial.print("[Status] Serial init: True");
    
    connectWifi(); //Connect to WiFi
    
}

void  loop()
{
    
}


void connectWifi( void )
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("[Status] WiFi: Connecting...");
        WiFi.begin(SSID, Password);
        delay(500);
    }
    Serial.print("[Status] WiFi: Connected!");

}
