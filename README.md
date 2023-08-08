# RFID-Based-Attendance-System-with-Mobile-App
An entire system integration to create a attendacne system of an office with RFID Cards and a mobile monitoring app.

## Intoduction
The traditional methods of tracking attendance in office environments often involve manual processes 
that are time-consuming and prone to errors. The RFID-based office attendance system aims to provide a 
streamlined and automated solution to accurately track employee attendance while ensuring secure 
access to the office premises.

## Components
- Arduino
- ESP8266
- Servo Motor (For demonstrating entrance unlocking trigger)
- Jumper Wires
- Buzzer, LED etc.

  
  ![image](https://github.com/tanvir-robin/RFID-Based-Attendance-System-with-Mobile-App/assets/95021955/29f02ed5-5f01-4fd9-86ef-81fbbb6aee34)


## System Architecture
The RFID-based office attendance system consists of three main components:
1. **Arduino with RFID Scanner and Servo Lock:** An Arduino board is utilized to control a servo motor that acts as a 
door lock mechanism. The system reads RFID card data and grants access by unlocking the door with servo motor if the card is approved.

3. **ESP8266 with Firebase:** An ESP8266 module is used to communicate with Firebase Realtime
Database. A serial communication is made with the Arduino and the ESP8266. When an RFID card is approved, Arduino sends the required card info to the ESP8266. And the ESP8266 sends the access information to Firebase, including employee details and timestamp.

5. **Mobile App:** A Flutter-based mobile app provides administrators with the ability to monitor and manage access logs in real-time. The app fetches data from Firebase and displays access history in a user-friendly interface

## Implementation Steps
1. Arduino and Servo Setup
- RFID reader is interfaced with the Arduino to read RFID card data.
- Servo motor is connected to the Arduino to act as a door lock.
- Appropriate libraries are used to control the RFID reader and servo.
2. ESP8266 and Firebase Integration
- The ESP8266 connects to the office Wi-Fi network.
- Firebase Realtime Database is configured to store access logs.
- ESP8266 sends data to Firebase whenever an RFID card is approved.
- ESP8266 uses a library called FIrebaseArduino to interact with Firebase.
3. Flutter App Development
- A Flutter app is developed for administrators to monitor attendance.
- Firebase package is used to fetch access log data from Firebase.
- The app displays access history with timestamps and employee detail
