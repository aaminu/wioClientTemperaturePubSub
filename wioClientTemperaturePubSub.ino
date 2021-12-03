#include <rpcWiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <DHT.h>
#include <ArduinoJson.h>


#include "config.h"

//Create a wifi object and a pubsub object using the wifi object
WiFiClient wioTerminalClient;
PubSubClient client( wioTerminalClient );

//declare the Temperature and Humidity object
DHT dht(D0, DHT11);

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
    dht.begin();
    
}

void  loop()
{
    float temp_humd[2] = {0};
    temp_humd[0] = dht.readTemperature();
    temp_humd[1] = dht.readHumidity();
    Serial.print("Temperature: "); Serial.println(temp_humd[0]); Serial.println("°C");
    Serial.print("Humidity: "); Serial.println(temp_humd[1]); Serial.println("%");

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
