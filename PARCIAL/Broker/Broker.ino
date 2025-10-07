// ========================= LIBRERÍAS =========================
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ========================= CONFIG WIFI ========================
const char* ssid = "Johan";             
const char* password = "americantruck"; 

// ========================= CONFIG MQTT ========================
const char* mqtt_server = "866fd998649c4b438956fda668c6930b.s1.eu.hivemq.cloud";  
const int mqtt_port = 8883; 
const char* mqtt_user = "hivemq.webclient.1759308443300"; 
const char* mqtt_pass = "2h?fy3N&LPav17DS*oU!"; 

// Temas MQTT
const char* topic_pub = "esp32/test";     
const char* topic_sub = "esp32/#";        

// ========================= CERTIFICADO SSL ====================
static const char *root_ca PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIFazCCA1OgAwIBAgIRAIIQz7DSQONZRGPgu2OCiwAwDQYJKoZIhvcNAQELBQAw
TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh
cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMTUwNjA0MTEwNDM4
WhcNMzUwNjA0MTEwNDM4WjBPMQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJu
ZXQgU2VjdXJpdHkgUmVzZWFyY2ggR3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBY
MTCCAiIwDQYJKoZIhvcNAQEBBQADggIPADCCAgoCggIBAK3oJHP0FDfzm54rVygc
h77ct984kIxuPOZXoHj3dcKi/vVqbvYATyjb3miGbESTtrFj/RQSa78f0uoxmyF+
0TM8ukj13Xnfs7j/EvEhmkvBioZxaUpmZmyPfjxwv60pIgbz5MDmgK7iS4+3mX6U
A5/TR5d8mUgjU+g4rk8Kb4Mu0UlXjIB0ttov0DiNewNwIRt18jA8+o+u3dpjq+sW
T8KOEUt+zwvo/7V3LvSye0rgTBIlDHCNAymg4VMk7BPZ7hm/ELNKjD+Jo2FR3qyH
B5T0Y3HsLuJvW5iB4YlcNHlsdu87kGJ55tukmi8mxdAQ4Q7e2RCOFvu396j3x+UC
B5iPNgiV5+I3lg02dZ77DnKxHZu8A/lJBdiB3QW0KtZB6awBdpUKD9jf1b0SHzUv
KBds0pjBqAlkd25HN7rOrFleaJ1/ctaJxQZBKT5ZPt0m9STJEadao0xAH0ahmbWn
OlFuhjuefXKnEgV4We0+UXgVCwOPjdAvBbI+e0ocS3MFEvzG6uBQE3xDk3SzynTn
jh8BCNAw1FtxNrQHusEwMFxIt4I7mKZ9YIqioymCzLq9gwQbooMDQaHWBfEbwrbw
qHyGO0aoSCqI3Haadr8faqU9GY/rOPNk3sgrDQoo//fb4hVC1CLQJ13hef4Y53CI
rU7m2Ys6xt0nUW7/vGT1M0NPAgMBAAGjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNV
HRMBAf8EBTADAQH/MB0GA1UdDgQWBBR5tFnme7bl5AFzgAiIyBpY9umbbjANBgkq
hkiG9w0BAQsFAAOCAgEAVR9YqbyyqFDQDLHYGmkgJykIrGF1XIpu+ILlaS/V9lZL
ubhzEFnTIZd+50xx+7LSYK05qAvqFyFWhfFQDlnrzuBZ6brJFe+GnY+EgPbk6ZGQ
3BebYhtF8GaV0nxvwuo77x/Py9auJ/GpsMiu/X1+mvoiBOv/2X/qkSsisRcOj/KK
NFtY2PwByVS5uCbMiogziUwthDyC3+6WVwW6LLv3xLfHTjuCvjHIInNzktHCgKQ5
ORAzI4JMPJ+GslWYHb4phowim57iaztXOoJwTdwJx4nLCgdNbOhdjsnvzqvHu7Ur
TkXWStAmzOVyyghqpZXjFaH3pO3JLF+l+/+sKAIuvtd7u+Nxe5AW0wdeRlN8NwdC
jNPElpzVmbUq4JUagEiuTDkHzsxHpFKVK7q4+63SM1N95R1NbdWhscdCb+ZAJzVc
oyi3B43njTOQ5yOf+1CceWxG1bQVs5ZufpsMljq4Ui0/1lvh+wjChP4kqKOJ2qxq
4RgqsahDYVvTH9w7jXbyLeiNdd8XM2w9U/t7y0Ff/9yi0GE44Za4rF2LN9d11TPA
mRGunUHBcnWEvgJBQl9nJEiU0Zsnvgc/ubhPgXRR4Xq37Z0j4r7g1SgEEzwxA57d
emyPxgcYxn/eR44/KJ4EBs+lVDR3veyJm+kXQ99b21/+jh5Xos1AnX5iItreGCc=
-----END CERTIFICATE-----
)EOF";


WiFiClientSecure espClient;
PubSubClient client(espClient);
LiquidCrystal_I2C lcd(0x27,16,2);


#define RXD2 16
#define TXD2 17
#define BTN_PIN 4
#define BUZZER_PIN 23

volatile bool botonPresionado = false; 
bool alarmaActivada = false;
float temperatura = 0;

void IRAM_ATTR botonISR() { botonPresionado = true; }
void conectarWiFi();
void conectarMQTT();
void callback(char* topic, byte* payload, unsigned int length);

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  attachInterrupt(digitalPinToInterrupt(BTN_PIN), botonISR, FALLING);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Iniciando...");

  conectarWiFi();
  espClient.setCACert(root_ca);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  conectarMQTT();
}

void loop() {
  if (!client.connected()) conectarMQTT();
  client.loop();

  // Leer dato del sensor
  if (Serial2.available()) {
    String dato = Serial2.readStringUntil('\n');
    dato.trim();
    if (dato.length()>0) {
      temperatura = dato.toFloat();
      Serial.println(temperatura); // Solo el número

      // Enviar temperatura al broker
      char tempStr[8];
      dtostrf(temperatura, 4, 1, tempStr);
      client.publish("esp32/temperatura", tempStr);

      // Activar alarma
      if (temperatura >= 30.0 && !alarmaActivada) {
        alarmaActivada = true;
        digitalWrite(BUZZER_PIN,HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("HOOOT!");
        client.publish(topic_pub,"Alarma activada");
      }

      // Apagar alarma
      if (temperatura < 29.0 && alarmaActivada) {
        alarmaActivada = false;
        digitalWrite(BUZZER_PIN,LOW);
        lcd.clear();
        client.publish(topic_pub,"Alarma desactivada");
      }
    }
  }

  // Silenciar con botón
  if (botonPresionado) {
    botonPresionado = false;
    if (alarmaActivada) {
      alarmaActivada = false;
      digitalWrite(BUZZER_PIN,LOW);
      lcd.clear();
      client.publish(topic_pub,"Alarma silenciada");
    }
  }
}

void conectarWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
  }
}

void conectarMQTT() {
  while(!client.connected()){
    String clientId = "ESP32Client-" + String(random(0xffff),HEX);
    if(client.connect(clientId.c_str(),mqtt_user,mqtt_pass)){
      client.subscribe(topic_sub);
    }else{
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length){

}
