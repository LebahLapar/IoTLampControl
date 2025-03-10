#define BLYNK_TEMPLATE_ID "TMPL6LPvZcrf8"
#define BLYNK_TEMPLATE_NAME "Lamp Control"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>


#define Relay_pin 13
#define DHT_pin 15
#define DHT_TYPE DHT22

char ssid[] = "Imalda";
char pass[] = "04271908";
char auth[] = "tfn-tdlxoCrrvGIYwV-HiRPTozoaGCKl";

DHT dht(DHT_pin, DHT_TYPE);
BlynkTimer timer;

void sendSensor() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V2, humidity);

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print("°C  |  Kelembaban: ");
  Serial.print(humidity);
  Serial.println("%");

  if(temperature > 29){
    digitalWrite(Relay_pin, HIGH);
  } else{
    digitalWrite(Relay_pin, LOW);
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(DHT_pin, INPUT);
  pinMode(Relay_pin, OUTPUT);
  dht.begin();
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(5000L, sendSensor);

  

}

void loop() {
  Blynk.run();
  timer.run();

}

BLYNK_WRITE(V1){
  int state = param.asInt();
  digitalWrite(Relay_pin, state == 1 ? LOW : HIGH);
}
