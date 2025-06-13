//ESP 8266 e DHT11
// URL para o ESP8266  https://arduino.esp8266.com/stable/package_esp8266com_index.json
#include <DHT.h>

// Define o pino onde o DHT11 está conectado

//#define DHTPIN D4  // GPIO2 no ESP8266
#define DHTPIN 2  // GPIO2 = D4 no NodeMCU

// Define o tipo de sensor: DHT11
#define DHTTYPE DHT11

// Inicializa o sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);     // Inicializa comunicação serial
  dht.begin();              // Inicializa o sensor DHT11
  Serial.println("Lendo dados do sensor DHT11...");
}

void loop() {
  // Aguarda o tempo mínimo entre leituras
  delay(2000);

  // Lê umidade e temperatura
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Verifica se a leitura falhou
  if (isnan(h) || isnan(t)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  // Imprime os valores no Serial Monitor
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");
}
