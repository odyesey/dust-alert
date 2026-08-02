#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* server = "http://YOUR_SERVER_IP:8000/api/sensor";

int pm25 = 40;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  randomSeed(micros());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    pm25 += random(-8, 9);

    if (random(100) < 5) {
      pm25 += random(80, 150);
    }

    pm25 = constrain(pm25, 0, 300);

    HTTPClient http;
    http.begin(server);
    http.addHeader("Content-Type", "application/json");

    String json = "{\"device_id\":\"esp32-001\",\"pm25\":" + String(pm25) + "}";

    int code = http.POST(json);

    Serial.print("PM2.5: ");
    Serial.print(pm25);
    Serial.print(" HTTP: ");
    Serial.println(code);

    http.end();
  }

  delay(5000);
}
