// Habilita la salida de debug por monitor serial
#define BLYNK_PRINT Serial  
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Token de autenticación generado por Blynk
char auth[] = "YOUR_BLYNK_AUTH_TOKEN"; 

// Credenciales de la red Wi-Fi
char ssid[] = "Diego_EF";  
char pass[] = "2195583";     

// Variable que almacena la corriente medida (debe actualizarse desde el sensor INA219)
float current = 0;

BlynkTimer timer;

// Función que envía la corriente al pin virtual V0 en la app Blynk
void sendCurrentData() {
  Blynk.virtualWrite(V0, current); // Enviando corriente medida (mA)
}

void setup() {
  Serial.begin(115200);
  Serial.println("Proyecto de Medición de Corriente");
  
  // Conexión a Wi-Fi y servidor de Blynk
  Blynk.begin(auth, ssid, pass);
  
  // Configurar envío de datos cada 10 segundos
  timer.setInterval(10000L, sendCurrentData);
}

void loop() {
  Blynk.run(); // Mantiene la conexión activa con Blynk
  timer.run(); // Ejecuta las tareas programadas como el envío de datos
}
