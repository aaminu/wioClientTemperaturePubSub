# wioClientTemperaturePubSub
This first part of this project aims to Publish Temperature and Humidity to an MQTT broker securely using the *Seeed wio Terminal*. The second part consist of an mqtt client running on another system, subscribed to the published topic, and saving the values in a csv file for later analysis. The seeed wio terminal also includes a simple Weather station interface that displays the current date, time, temperature and humidity. 

## The First Part: Weather Station
The components required for the first part are: 
- Seeed Wio Terminal ([Here](https://wiki.seeedstudio.com/Wio-Terminal-Getting-Started/))
- Grove Temperature&Humidity Sensor (DHT11) ([Here](https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/))

I would want to assume you know how to add the board to your Arduino Board Manager. However, if that is not the case, kindly read through this [wiki](https://wiki.seeedstudio.com/Wio-Terminal-Getting-Started/). 


To use these code the following, please do the follow.
1. rename the *config_.h*  to *config.h*
2. fill in the content especially your wifi and password. You can leave the NTP parameter as it is
3. Install the following into your library if not already there(i.e. Sketch -> Include Libarary -> Manage Libraries).
    - Seeed *Arduino rpcWiFi* (version: 1.0.5)
    - Seeed *Arduino rpcUnified* (version: 2.1.3)
    - Seeed *Arduino RTC* (version: 2.0.0)
    - DHT sensor library (min version: 1.4.1)
The content of the code is well commented to carry you along. Take your time to go through it as this isn't the usual weather station. It tries to intoduce you to other functionalities like interrupts, usage of the WiFi, Real time clock etc.. 

### How it works
The wio terminal makes use of:
1. the grove DHT sensor to measure Humidity and Temperature. 
2. WiFiUDP  to update it's rtc for displaying realtime and date.
3. WiFiSecure to connect securely to the MQTT Broker using SSL/TLS, and publish the sensor data
4. One of the buttons available on the wio terminal to wake the screen, display the date, time and sensor data.

<b><u>NOTE:</u></b>

1. To turn on the screen, Press *Button_C* (configurable), and also the same button to turn it off. The display stays on for a period of 3mins. The system measures Temperature and Humidity every 5mins.
2. You need to have the ca_cert for the MQTT broker.

## The Second Part: Creating the Storage Client
This part is a simple python script that subscribe to the topic which the weather station publishes. The major requirement is to use python@3.x≥5 and have [**paho-mqtt**](https://pypi.org/project/paho-mqtt/) installed. 

Kindl rename config_.py to config.py and populate as required and place the *ca-cert.crt* in the same directory. 

### How it works
1. The script connects to the broker securely using SSL/TLS.
2. Each recieved message is saved in csv file with timestamps

<b><u>NOTE:</u></b>

If you are using a self-signed certificate, paho-mqtt libarary doesn't support verifying such a ca-cert. You will need to set the following 
```python
client.tls_insecure_set(True) # Because self-signed certificate is used
````
The above line tells the paho-mqtt client not to verify the sever identity. Please only do this if you are absolutely certain of the server. 





