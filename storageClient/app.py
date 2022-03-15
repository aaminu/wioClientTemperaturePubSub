from datetime import datetime
from os import path
from config import *
import paho.mqtt.client as mqtt
import json
import time
import csv
import ssl

topic = "Home/Room"
client_name = "StorageCsvClient"

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    client.subscribe(topic)

def on_message(client, userdata, msg):
    payload = json.loads(msg.payload.decode())
    print("Message received:", payload)
    
    temperature_file_name = 'temperature.csv'
    fieldnames = ['date', 'temperature', 'humidity']

    if not path.exists(temperature_file_name):
        with open(temperature_file_name, "w") as csv_file:
            writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
            writer.writeheader()
    
    with open(temperature_file_name, "a") as temp_file:
        temp_writer = csv.DictWriter(temp_file, fieldnames=fieldnames)
        temp_writer.writerow({
            'date': datetime.now().astimezone().replace(microsecond=0).isoformat(),
            'temperature': payload['temp'], 
            'humidity': payload['humid']
        })


client = mqtt.Client(client_name)
client.on_connect = on_connect
client.on_message = on_message
client.tls_set(ca_certs="mosquitto-certificate-authority.crt", cert_reqs=ssl.CERT_REQUIRED,
    tls_version=ssl.PROTOCOL_TLS)
client.tls_insecure_set(True) # Because self signed certificate is used
client.username_pw_set(USERNAME, password=PASSWORD)


client.connect(server, port=port, keepalive=60)
client.loop_start()

while True:
    time.sleep(2)