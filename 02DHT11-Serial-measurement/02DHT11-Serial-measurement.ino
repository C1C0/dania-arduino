#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() { 
  
  Serial.print("Current humidity = ");
  Serial.print(dht.readHumidity());
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(dht.readTemperature()); 
  Serial.println("C  ");

  delay(5000);
}
