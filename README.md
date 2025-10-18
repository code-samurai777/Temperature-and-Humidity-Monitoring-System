# Temperature and Humidity Monitoring System - Simulation

![Arduino](https://img.shields.io/badge/Built%20with-Arduino-blue)
![Simulation](https://img.shields.io/badge/Simulation-Tinkercad-orange)
![License](https://img.shields.io/badge/License-MIT-green)

---

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Components Used](#components-used)
4. [Circuit Diagram](#circuit-diagram)
5. [Demo / Screenshots](#demo--screenshots)
6. [Code Explanation](#code-explanation)
7. [How It Works](#how-it-works)
8. [Simulation](#simulation)
9. [Data Visualization](#data-visualization)
10. [Author](#author)

---

## Project Overview
**Temperature and Humidity Monitoring System** is an Arduino-based project designed to measure and display temperature and humidity in real-time. A moving average filter is applied to smooth out the sensor noise, and data is visualized manually in Excel for further analysis.  
*Short description:* An Arduino-based temperature and humidity monitoring system with data filtering and visualization.

---

## Features
- Real-time measurement and display of temperature (°C) and humidity (%)  
- Moving Average filtering to smooth sensor noise  
- Visual output on 16x2 LCD and serial monitor  
- Manual plotting of data for analysis  
- Fully simulated using Tinkercad

---

## Components Used
- Arduino UNO (simulated)
- TMP36 Temperature sensor
- Potentiometer (x2)
- 16x2 LCD Display
- 1k and 10k resistors
- Push button
- Jumper Wires 

---

## Circuit Diagram
Schematic for the project can be accessed [here](#) <!-- Replace with your schematic link later -->

---

## Demo / Screenshots
**Simulation images and video:**  
*Place images/screenshots here after uploading to GitHub.*

- Circuit view(with result): `circuit_diagram.png`  
- Simulation Demo: `simulation_demo.mp4`

---

## Code Explanation
**Main Arduino Code (`tinkercad_code.ino`):**  
- First potentiometer is used at lcd pin V0 for output
- Second potentiometer is used at arduino pin A1 to measure humidity.
- Implements a **Moving Average Filter** to reduce noise  
- Prints filtered values to serial monitor  
- Displays temperature & humidity on 16x2 LCD
  
---

## How It Works

 - Arduino reads sensor values from potentiometer every 2 seconds
 - Moving Average filter calculates smoothed readings
 - Filtered values displayed on LCD and serial monitor
 - Data recorded manually for Excel plotting

---

## Simulation Link
[Tinkercad Project Link](https://www.tinkercad.com/things/lbUgksHqRy9-temperature-and-humidity-monitoring-system-with-kalman-filtering?sharecode=xvusei1U_S84yZDGYI4ZSp1HwLq14AfvHwRIXmo6sfg)

---


## Data Visualization

- Serial monitor output can be plotted using Excel
- Manual plotting helps verify filtered readings
- Shows stability and reliability of measurements over time

---


## Author

**Made by:** Sarthak Omar  
**Role:** Instrumentation Project (Simulation)  
**Tools:** Arduino, Tinkercad, Excel, C++
