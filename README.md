Air Quality Monitor

This repository contains the code and resources for an Air Quality Monitoring System using MQ-7 and CNT5 sensors with an ESP32 microcontroller. This project provides real-time monitoring and analysis of air quality parameters such as carbon monoxide (CO) and particulate matter (PM2.5), offering insights to improve environmental and personal health.

Features

Real-time Monitoring: Measures CO levels and PM2.5 concentration in the environment.

ESP32 Integration: Utilizes the ESP32 microcontroller for data acquisition and processing.

IoT-enabled: Supports connectivity to IoT platforms for data visualization and storage.

User-friendly: Outputs air quality data for easy interpretation.

Components Used

Hardware:

ESP32 Microcontroller: Used for data collection and communication.

MQ-7 Sensor: Measures carbon monoxide (CO) levels in the air.

CNT5 Sensor: Measures particulate matter (PM2.5).

Connecting Wires

Breadboard or PCB (for connections)

Power Supply

Software:

Arduino IDE: For programming the ESP32 microcontroller.

PlatformIO (optional): An alternative IDE for embedded development.

IoT Platform (optional): For cloud-based data visualization (e.g., Blynk, ThingSpeak, etc.).

Setup and Installation

Prerequisites:

Install the Arduino IDE or PlatformIO.

Install the ESP32 board package in the Arduino IDE (guide).

Add required libraries for sensors and IoT communication (if used).

Steps:

Clone this repository:

git clone https://github.com/anish1108/Air-Quality-Monitor.git

Connect the hardware components as per the wiring diagram (provided in this repository).

Open the .ino file in the Arduino IDE.

Configure WiFi credentials (if IoT functionality is enabled) in the code.

Select the correct board (ESP32) and port in the Arduino IDE.

Upload the code to the ESP32.

Usage

Hardware Setup: Assemble the components and ensure correct connections.

Power the Device: Power the ESP32 using a USB cable or battery.

Monitor Data:

View real-time air quality readings on the serial monitor.

(Optional) Send data to an IoT platform for visualization.

Code Overview

main.ino: Contains the primary code for data acquisition and processing.

libraries/: Includes any custom or external libraries required for the sensors.

config/: Configuration files for WiFi credentials and other settings (if applicable).

docs/: Documentation, including wiring diagrams and project notes.

Wiring Diagram

Future Improvements

Add support for additional air quality sensors (e.g., MQ-135).

Implement mobile app integration for notifications.

Enhance data visualization with dashboards.

Introduce ML-based predictions for air quality trends.
