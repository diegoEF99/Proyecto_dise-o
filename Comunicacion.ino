#define BLYNK_PRINT Serial  
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN"; 
char ssid[] = "Diego_EF";  
char pass[] = "2195583";     

float current = 0;

BlynkTimer timer;

void sendCurrentData() {
  Blynk.virtualWrite(V0, current); // Enviando corriente medida (mA)
}

void setup() {
  Serial.begin(115200);
  Serial.println("Proyecto de Medición de Corriente");
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10000L, sendCurrentData);
}

void loop() {
  Blynk.run();
  timer.run();
}
