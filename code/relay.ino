#define BLYNK_TEMPLATE_ID "TMPL6LPvZcrf8"
#define BLYNK_TEMPLATE_NAME "Lamp Control"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define Relay_Pin 14

char ssid[] = "Imalda";
char pass[] = "04271908";
char auth[] = "tfn-tdlxoCrrvGIYwV-HiRPTozoaGCKl";

void setup() {
  Serial.begin(115200);
  pinMode(Relay_Pin, OUTPUT);
  digitalWrite(Relay_Pin, HIGH);
  Blynk.begin(auth,ssid, pass);

}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1){
  int state = param.asInt();
  digitalWrite(Relay_Pin, state == 1 ? LOW : HIGH);
}



