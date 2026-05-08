# IoT Based Air Quality Monitoring System

## 📌 Project Overview
This project is an IoT-based Air Quality Monitoring System developed using ESP32, MQ135 gas sensor, DHT11 sensor, LCD display, and Blynk IoT platform. The system continuously monitors air quality, temperature, and humidity in real time and displays the data on both an LCD screen and the Blynk mobile application.

The project helps users monitor environmental conditions remotely through the internet.


## 🚀 Features
- Real-time air quality monitoring
- Temperature and humidity monitoring
- Wireless data transmission using Wi-Fi
- Remote monitoring using Blynk IoT
- LCD display output
- Portable and low-cost system
- Alert indication when air quality exceeds threshold values


## 🛠 Components Used
- ESP32 DevKit V1
- MQ135 Air Quality Sensor
- DHT11 Temperature & Humidity Sensor
- 16x2 LCD Display with I2C Module
- Jumper Wires
- Breadboard
- USB Cable
- Wi-Fi Connection


##  Circuit Connections

### MQ135 Sensor
| MQ135 Pin | ESP32 Pin |
|----------|------------|
| VCC      | 3.3V       |
| GND      | GND        |
| AO       | GPIO 34    |

### DHT11 Sensor
| DHT11 Pin | ESP32 Pin |
|-----------|------------|
| VCC       | 3.3V       |
| GND       | GND        |
| DATA      | GPIO 4     |

### LCD I2C Connections
| LCD Pin | ESP32 Pin |
|---------|------------|
| VCC     | 5V         |
| GND     | GND        |
| SDA     | GPIO 21    |
| SCL     | GPIO 22    |

---

##  Blynk IoT Setup
1. Create a template in Blynk IoT.
2. Create datastreams for:
   - Air Quality
   - Temperature
   - Humidity
3. Copy:
   - BLYNK_TEMPLATE_ID
   - BLYNK_TEMPLATE_NAME
   - BLYNK_AUTH_TOKEN
4. Paste them into the Arduino code.
5. Connect the device to Wi-Fi.


## 💻 Software Used
- Arduino IDE
- Blynk IoT Platform


## 📚 Libraries Required
Install the following libraries in Arduino IDE:
- WiFi.h
- BlynkSimpleEsp32.h
- DHT.h
- Wire.h
- hd44780.h


## ▶️ Working Principle
1. MQ135 sensor detects air quality/gas concentration.
2. DHT11 measures temperature and humidity.
3. ESP32 reads sensor data.
4. Data is displayed on LCD.
5. ESP32 sends data to Blynk Cloud through Wi-Fi.
6. User monitors values remotely using the Blynk mobile app.


## 📊 Applications
- Smart Homes
- Industrial Air Monitoring
- Pollution Monitoring
- Weather Monitoring Systems
- Indoor Air Quality Analysis


## 🔮 Future Scope
- Add GSM module for SMS alerts
- Add buzzer alert system
- Store data in cloud database
- Add AI-based pollution prediction
- Integrate with smart home systems


## ⚠️ Limitations
- Requires internet connection
- MQ135 readings may vary due to environmental conditions
- DHT11 has limited accuracy
- Sensor calibration is required for precise measurements




## 📄 License
This project is for educational purposes.
