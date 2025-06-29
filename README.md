<p align="center">
  <a href="https://ibb.co/GvVyXk4t">
    <img src="https://i.ibb.co/JRzVN2wy/project-X2019.webp" alt="project-X2019" width="300"/>
  </a>
</p>

<h1 align="center">ProjectX2019: RoboRAVE International 2019 Fire Fighting Robot</h1>
<p align="center"><em>Advanced Autonomous Fire Fighting Robot for RoboRAVE International 2019 in China</em></p>

## Overview
ProjectX2019 is an advanced Arduino Mega-based autonomous robot designed to compete in the RoboRAVE International 2019 Fire Fighting Challenge held in China. This sophisticated robot features multiple sensor arrays, dual microcontroller architecture, and advanced navigation algorithms to locate and extinguish candles autonomously. The robot incorporates temperature monitoring, LED displays, and multiple operational modes for optimal performance in competitive environments.

---

# ProjectX2019: RoboRAVE International 2019 Fire Fighting Robot

This repository contains the code and documentation for our advanced autonomous fire fighting robot designed to compete in the RoboRAVE International 2019 Fire Fighting Challenge in China.

## Robot Specifications

### Motors
- **2 Stepper Motors** for differential drive locomotion
  - Step resolution: Configurable microstepping
  - Step time: 500 microseconds (normal), 2400 microseconds (slow)
  - Turn time: 2400 microseconds for precise navigation

### Sensors

#### Candle Detection Sensors (42 total)
- **7 Candle sensor rails** with 6 sensors each (stacked vertically)
- **Rail 1:** 6 sensors
- **Rail 2:** 6 sensors
- **Rail 3:** 6 sensors
- **Rail 4:** 6 sensors
- **Rail 5:** 6 sensors
- **Rail 6:** 6 sensors
- **Rail 7:** 6 sensors
- **2 Analog backup candle sensors** for redundancy
- **Detection threshold:** 970 for backup sensors

#### Line Following Sensors (6 total)
- **6 Analog line sensors** arranged in hexagonal pattern
- **Line detection threshold:** 350 (configurable)
- **Arrangement:** Hexagonal pattern for comprehensive line detection

#### Obstacle Detection Sensors (7 total)
- **7 Ultrasonic sensors** for 360-degree obstacle detection
- **Range detection:** 13cm (front/back), 10cm (sides)
- **Positioned around robot perimeter** for complete coverage

#### Environmental Sensors (2 total)
- **2 DHT11 sensors** for temperature and humidity monitoring
- **Used for environmental data logging and system monitoring**

#### Control Sensors
- **Start button:** For competition control
- **Mode switch:** Toggle between normal and FCC modes
- **LED indicator:** Status indication before start

### Actuators
- **Servo motor:** Controls propeller for candle extinguishing
  - ON position: 102 degrees
  - OFF position: 180 degrees

### Display Systems
- **LCD display:** 16x2 I2C display for data visualization
- **NeoPixel ring:** 24 RGB LEDs for status indication and effects
- **Status LED:** Single LED for basic status indication

### Control System
- **Primary microcontroller:** Arduino Mega
- **Secondary microcontrollers:** 9 Arduino Nano boards for distributed sensor processing
  - **7 Arduino Nano boards** for candle sensor arrays (1 per rail)
  - **1 Arduino Nano board** for ultrasonic sensor processing
  - **1 Arduino Nano board** for display systems (LCD and NeoPixel)
- **Communication:** Serial communication at 9600 baud
- **Power:** Autonomous operation with onboard power supply

## Robot Behavior

The robot operates autonomously with the following advanced behaviors:
1. **Multi-mode operation:** Normal mode and FCC (Fire Candle Control) mode
2. **Advanced line following** using hexagonal sensor array
3. **Precise candle detection** using 9-sensor array
4. **360-degree obstacle avoidance** using 7 ultrasonic sensors
5. **Environmental monitoring** with temperature and humidity sensors
6. **Visual feedback** through LCD and LED systems
7. **Adaptive navigation** with multiple turning algorithms
8. **Candle extinguishing** using propeller system

## Project Structure

### Main Project Files
- `main_v2.ino` - Arduino sketch for version 2
- `main_v2.cpp` - Implementation file for version 2
- `main_v2.h` - Header file for version 2
- `main_v3.ino` - Arduino sketch for version 3
- `main_v3.cpp` - Implementation file for version 3
- `main_v3.h` - Header file for version 3
- `main_v4.ino` - Arduino sketch for version 4
- `main_v4.cpp` - Implementation file for version 4
- `main_v4.h` - Header file for version 4
- `main_v5.ino` - Arduino sketch for version 5 (current)
- `main_v5.cpp` - Implementation file for version 5 (current)
- `main_v5.h` - Header file for version 5 (current)

### Project Directories
- `main_v2/` - Directory containing version 2 Arduino sketch
- `main_v3/` - Directory containing version 3 Arduino sketch
- `main_v4/` - Directory containing version 4 Arduino sketch
- `main_v5/` - Directory containing version 5 Arduino sketch

### Sensor Modules
- `candle.cpp` - Candle detection algorithms
- `candle.h` - Candle detection header
- `ultrasonic.cpp` - Ultrasonic sensor processing
- `ultrasonic.h` - Ultrasonic sensor header
- `show_sensors.cpp` - Sensor data display
- `show_sensors.h` - Sensor display header

### Display Systems
- `ring_and_led.cpp` - NeoPixel ring and LCD control
- `ring_and_led.h` - Display system header

### Communication
- `read_mega.cpp` - Inter-microcontroller communication
- `read_mega.h` - Communication header

### Dependencies
- `libraries/` - External libraries directory
  - `Servo/` - Servo motor control library
  - `Wire/` - I2C communication library
  - `Adafruit_NeoPixel-master/` - RGB LED control library
  - `Adafruit_GFX_Library/` - Graphics library
  - `Adafruit_SSD1306/` - OLED display library
  - `Adafruit_BusIO/` - I2C/SPI bus library
  - `DHT/` - Temperature/humidity sensor library

### Configuration Files
- `.gitignore` - Git ignore rules
- `.DS_Store` - macOS system files (ignored by git)
- `LICENSE` - Project license

## Challenge Overview

This robot is designed for the RoboRAVE International 2019 Fire Fighting Challenge in China, where it must:
- Navigate autonomously within a defined arena
- Locate and extinguish candles without physical contact
- Avoid obstacles and walls
- Complete the task within time limits
- Operate in competitive international environment

---

## Competition Rules & Specifications

### Challenge Goal

The objective of this challenge is to design, build, and program an autonomous robot capable of locating and extinguishing four randomly placed candles within a field outlined by a white and black line. The robot must extinguish the candles without making physical contact with them.

### Divisions

This challenge typically includes teams from:
- Middle School
- High School  
- "Big Kids" divisions

### Robot Requirements & Constraints

Our robot adheres to the following requirements and design constraints for the 2019 Fire Fighting Challenge:

- **Autonomy**: The robot operates autonomously
- **Cost**: The total cost of the robot is $1,500 USD or less
- **Extinguishing System Control**: The robot's program can control the start and stop of its extinguishing system via a sensor that interacts with either the candle or the circle the candle is placed on
- **Safety Guard**: If a high-speed propeller is used, the robot has a safety guard in place
- **Sensors and Processors**: Multiple sensors and processors are allowed
- **Volume**: The robot's volume does not exceed 65,030 cm³

### General Rules of Play

- **Starting Position**: The robot begins each heat at a spot along the border chosen by the challenge coordinator
- **First Candle Visibility**: The first candle is in plain view of the robot at the start of the challenge
- **Time Limit**: The robot has 3 minutes to extinguish all four candles
- **Player Interaction**: Only players can operate and manipulate the robot during a heat. If a player touches the robot after the challenge begins, the run ends, and scoring is based on the number of candles extinguished at that point
- **Practice Tracks**: Official tracks are available for practice when not in use by competitors
- **Official Runs**: Teams get 10 official scored runs during the challenge scoring period
- **Tournament Selection**: The total of the 5 highest official scores are used to determine tournament selection

### Challenge Specifications

#### The Track

- **Field Dimensions**: The challenge field is 2.4m × 3.5m
- **Border**: A border is constructed using white and black duct tape. The white duct tape is 7.5cm wide with a 2.5cm black duct tape line down its center
- **Random Placement**: Candles and walls are randomly placed for every run
- **Lighting Conditions**: The challenge may be held in areas with natural light, so the robot is engineered to adapt to changing lighting conditions

#### The Candles

- **Placement**: Candles stand at the center of a white vinyl circle, indicated by a 5cm diameter black circle
- **Height**: Candle heights vary between 10cm and 45cm
- **Circle Dimensions**: The circle has a 40cm diameter, with a 2.5cm black line 2.5cm in from its outer edge

**Wall Obstructions**: Candles can be blocked by walls in varying configurations:
- 1 candle: No wall
- 1 candle: 1 wall
- 1 candle: 2 walls
- 1 candle: 3 walls

#### The Walls

- **Width**: Wall widths vary from 20cm to 35cm
- **Height**: Walls are 40cm tall
- **Bases**: Walls are held up by wooden bases that are 3.5cm tall and may span the approximate width of the wall

> **Note**: All challenge dimensions are approximate.

### Scoring

Scoring is based on the number of candles extinguished. A "remaining time bonus" is awarded only if all four candles are extinguished. Otherwise, only points for extinguished candles are awarded.

#### Penalty Rules

A 50% penalty off the candle's value is applied if:
- A candle is extinguished by the robot when it is completely outside the circle
- The candle is touched during the process of extinguishing the flame

The "process of extinguishing the lit candle" is defined as: entering into the circle, extinguishing, and leaving the circle. During this time, the robot cannot make contact with the candle.

Previously extinguished candles become obstacles and do not count as a penalty if touched.

#### Scoring Matrix

| Number of Candles Extinguished | First | Second | Third | Fourth | Total Possible Score |
|--------------------------------|-------|---------|-------|--------|---------------------|
| Half points due to penalty*    | 50    | 100     | 150   | 200    | 1000               |
| Full Points                    | 100   | 200     | 300   | 400    |                    |
| **Time Bonus**                 |       |         |       |        | **0-180** (Clock counts down from 180 seconds and stops when the robot extinguishes the fourth candle) |

### Tournament Scoring

The top eight teams will compete in a final tournament. Advancing teams are seeded into the tournament bracket based on their aggregate score. The "Runner Up" is used to determine 3rd place based on the outcome of the semi-finals.

---

## 🔐 License

This project is licensed under the **Non-Commercial Public License (NCPL v1.0)**  
© 2025 Jakub Ešpandr - Born4FLight, FlyCamCzech

See the [LICENSE](https://github.com/Jakub-Espandr/ProjectX2019/raw/main/LICENSE) file for full terms.