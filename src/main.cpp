#define BLYNK_TEMPLATE_ID "TMPL5037QLVnF"
#define BLYNK_TEMPLATE_NAME "uwu"
#define BLYNK_AUTH_TOKEN "izwoM5CCikaAlmDQGJ2MBbuyXl4XeUiH"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Ticker.h>

// Informations de votre réseau WiFi (hotspot mobile)
char ssid[] = "Galaxy A13B7E0";
char pass[] = "txeh8505";

// Broche où le capteur LMT85 est connecté
const int sensorPin = 34;

// Déclaration de la fonction readTemperature
void readTemperature();

// Déclaration du timer
Ticker timer;

void setup()
{
  // Initialisation de la communication série
  Serial.begin(115200);
  
  // Connexion à Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initialisation du timer pour lire la température toutes les 2 secondes
  timer.attach(2, readTemperature);

}

void loop()
{
  // Exécution de Blynk
  Blynk.run();
}

// Définition de la fonction readTemperature
void readTemperature()
{
  int sensorValue = analogReadMilliVolts(sensorPin);
  float temperature = (sensorValue  - 1569) / -8.2; // Conversion de la tension en température

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
    
   // Envoyer la température à Blynk (par exemple sur le Virtual Pin V0)
  Blynk.virtualWrite(V0, temperature);
}
