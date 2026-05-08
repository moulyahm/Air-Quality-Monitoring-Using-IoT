#define BLYNK_TEMPLATE_ID "your Blynk Template Id"
#define BLYNK_TEMPLATE_NAME "Your Template Name"
#define BLYNK_AUTH_TOKEN "Auth Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <DHT.h>


char ssid[] = "WiFi Name";
char pass[] = "Passward";


#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


#define MQ135_PIN 34


hd44780_I2Cexp lcd;


BlynkTimer timer;


void sendData() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int air = analogRead(MQ135_PIN);

  String status;
  if (air < 800) status = "Good";
  else if (air < 1800) status = "Moderate";
  else status = "Poor";

  Serial.println("------ DATA ------");
  Serial.print("Temp: "); Serial.println(temp);
  Serial.print("Hum: "); Serial.println(hum);
  Serial.print("Air: "); Serial.println(air);
  Serial.print("Status: "); Serial.println(status);

  
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, air);
  Blynk.virtualWrite(V3, status);
}


void displayLCD() {
  static int screen = 0;

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int air = analogRead(MQ135_PIN);

  String status;
  if (air < 800) status = "Good";
  else if (air < 1800) status = "Moderate";
  else status = "Poor";

  lcd.clear();

  switch (screen) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Temperature");
      lcd.setCursor(0, 1);
      lcd.print(temp); lcd.print(" C");
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Humidity");
      lcd.setCursor(0, 1);
      lcd.print(hum); lcd.print(" %");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Air Quality");
      lcd.setCursor(0, 1);
      lcd.print(air);
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Status");
      lcd.setCursor(0, 1);
      lcd.print(status);
      break;
  }

  screen = (screen + 1) % 4;
}


void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  int status_lcd = lcd.begin(16, 2);
  if (status_lcd) {
    Serial.println("LCD not detected!");
    while (1);
  }

  lcd.backlight();
  dht.begin();

  // Connect Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Timers
  timer.setInterval(2000L, sendData);     // send data
  timer.setInterval(2500L, displayLCD);   // change LCD
}


void loop() {
  Blynk.run();
  timer.run();
}
