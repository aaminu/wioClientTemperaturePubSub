//WiFi Crendtials
const char * SSID = "<SSID HERE>";
const char * PSK = "<PASSKEY HERE>";

//NTP 
const char * TimeServer = "time.nist.gov"; // extenral NTP server e.g. time.nist.gov
const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message

//MQTT
const char *ID = "WIO-Terminal-Client";
const char *TOPIC = "Home/Room";
const char *USERNAME = "<USERNAME if used else leave empty>";
const char *PASSWORD = "<USERNAME if used else leave empty>";

const char *server = "<SERVER IP or URL>";

// SAMPLE CA CERT. Use your selfsigned root_ca if mqtt is hosted securely locally,
//else use the one provided by the mqtt broker service
//This is just a sample and usually longer than this
const char *root_ca = 
"-----BEGIN CERTIFICATE-----\n"
"3iguiW8kdWhCtQiiD5TBIYl1Rn5YfyOzd519+vIHz+QxLnh6+DSyEjPqlpRgDQg5\n"
"lgtb8yFB98QAhoqOvjFKkTMkQDT64CSqGSIb3DQEBCwUAA4IBAQDmf6D9FzSf8wSf8\n"
"4+8TAgMBAAGjUzBRMB0GA1UdDgQWBBSX7mtuztQlglIPWajkDUAIUg79XjAfBgNV\n"
"HSMEGDAWgBSX7mtuztQlglIPWajkDUAIUg79XjAPBgNVHRMBAf8EBTADAQH/MA0G\n"
"8yFhcY3l7t8Ftda6yLeMrDt51tAb2j2k4IzBpuOOopVxZRcs/Ms3tk5FKrRNKpiP\n"
"umP4jd3IJg9KVSqCjrREkXQYGOV6mCZajyT9oiRQRF1239y5ESf8wSf8wSf8wSfO\n"
"3iguiW8kdWhCtQiiD5TBIYl1Rn5YfyOzd519+vIHz+QxLnh6+DSyEjPqlpRgDQg5\n"
"-----END CERTIFICATE-----\n";