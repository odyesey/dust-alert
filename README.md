# Aralkum Dust Alert Sensor (MVP)

An ESP32-based prototype that simulates dust sensor readings and sends them to a backend API. The project demonstrates how an IoT device can monitor air quality and provide early warnings about dust storms in the Aralkum Desert.

## Overview

The Aralkum Desert, formed on the dried seabed of the Aral Sea, is a major source of dust and salt storms that affect nearby communities. This MVP demonstrates the core architecture of a dust monitoring system by generating simulated PM2.5 measurements and transmitting them over Wi-Fi.

## Features

* ESP32-based IoT device
* Simulated PM2.5 sensor data
* Wi-Fi connectivity
* HTTP POST requests to a REST API
* Easy integration with dashboards and alert systems
* Modular design for replacing simulated data with a real dust sensor

## How It Works

1. The ESP32 connects to a Wi-Fi network.
2. It generates realistic PM2.5 values.
3. Every few seconds, the data is sent to the backend API.
4. The server stores the data and can trigger alerts when dust levels exceed a threshold.

Example JSON

{
  "device_id": "esp32-001",
  "pm25": 87
}

## Hardware

* ESP32 Development Board

Future versions can use real particulate matter sensors such as:

* PMS5003
* SDS011
* SEN55

## Getting Started

1. Open the project in the Arduino IDE.
2. Install the ESP32 board package.
3. Update your Wi-Fi credentials.
4. Set the backend API URL.
5. Upload the code to the ESP32.
6. Start your backend server and monitor incoming data.

## Future Improvements

* Integrate a real PM2.5 sensor
* GPS location support
* Battery-powered deployment
* MQTT communication
* OTA firmware updates
* SMS and mobile notifications
* Interactive monitoring dashboard

## License

This project is released under the MIT License.
