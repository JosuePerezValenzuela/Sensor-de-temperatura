
#include <OneWire.h>
#include <DallasTemperature.h>

const byte pinDatosDQ = 3;
OneWire oneWireObjeto(pinDatosDQ);
 DallasTemperature sensorsDS18B20(&oneWireObjeto);

 const char* ssid = "";
 const char* password = "";

WiFiClient espClient;
PubSubClient client (espClient);
void setup_wifi(){
  display.init();
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment (TEXT_ALIGN_LEFT);
  display.drawString(1, 5, "Conenctado a:");
  display.drawString(1, 15, ssid);
  display.display();
  }
  WiFi.begin(ssid, password);
  int x = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.setFont(ArialMT_Plain_24);
    display.drawString(0+x, 25, ".");
    x = x + 3;
    if (x>124) {
      x = 0;
      display.clear();
      display.setFont (ArialMT_Plain_10);
      display.setTextAlignment (TEXT_ALIGN_LEFT);
      display.drawString(1, 5, "COnectando a:");
      display.drawString(1, 15, ssid);
      }
      display.display();
    }
    
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensorsDS18B20.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Mandando comandos a los sensores");
  sensorsDS18B20.requestTemperatures ();
  Serial.println("Temperatura del sensor");
  Serial.println(sensorsDS18B20.getTempCByIndex(0));
  delay(1000);
}
