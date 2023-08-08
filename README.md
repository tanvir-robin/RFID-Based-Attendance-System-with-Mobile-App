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

## Database
Used Firebase Realtime Database to store project Data and access logs. The user information is stored in Cloud Firestore to get instant access. Any of the database can be used for both purposes.

  



## System Architecture
The RFID-based office attendance system consists of three main components:
1. **Arduino with RFID Scanner and Servo Lock:** An Arduino board is utilized to control a servo motor that acts as a 
door lock mechanism. The system reads RFID card data and grants access by unlocking the door with servo motor if the card is approved.

3. **ESP8266 with Firebase:** An ESP8266 module is used to communicate with Firebase Realtime
Database. A serial communication is made with the Arduino and the ESP8266. When an RFID card is approved, Arduino sends the required card info to the ESP8266. And the ESP8266 sends the access information to Firebase, including employee details and timestamp.

5. **Mobile App:** A Flutter-based mobile app provides administrators with the ability to monitor and manage access logs in real-time. The app fetches data from Firebase and displays access history in a user-friendly interface

## Schematic Diagram
  ![final sketch](https://github.com/tanvir-robin/RFID-Based-Attendance-System-with-Mobile-App/assets/95021955/1ea8e111-a74f-4b9a-ad8f-df6e007f591a)


## Implementation
Implmentation Steps
1. **Arduino and Servo Setup**
- RFID reader is interfaced with the Arduino to read RFID card data.
- Servo motor is connected to the Arduino to act as a door lock.
- Appropriate libraries are used to control the RFID reader and servo.
2. **ESP8266 and Firebase Integration**
- The ESP8266 connects to the office Wi-Fi network.
- Firebase Realtime Database is configured to store access logs.
- ESP8266 sends data to Firebase whenever an RFID card is approved.
- ESP8266 uses a library called FIrebaseArduino to interact with Firebase.
3. **Flutter App Development**
- A Flutter app is developed for administrators to monitor attendance.
- Firebase package is used to fetch access log data from Firebase.
- The app displays access history with timestamps and employee detail.


## Mobile App made with FLutter SDK

> The app is very basic yet. Just implemented the access logs. No design architecture is maintained. Will upadate the app soon with a beautiful and friendly UI. 

![smartmockups_ll0crhv9](https://github.com/tanvir-robin/RFID-Based-Attendance-System-with-Mobile-App/assets/95021955/fc6bb5b5-6106-4fa0-b740-820efd62498a)


## Benifits and Features
  - [x] Automated Attendance.
  - [x] Secure Access. (Only authorized People can access with authorized card)
  - [x] Real-time Monitoring with Mobile App.
  - [x] Red Signal for invalid access request. (Implemented with a buzzer in prototype)
  - [x] Separate Database for user details associated with individual authrized card.
  - [ ] Full administrator controll via mobile app. Admin can add new authorized user or remove existing with the mobile app (Coming soon. Working on it)
  - [ ] Efficient reporting by the app. (Coming soon)
  - [x] Easy to install and very cheap to implement.


## Get in touch
> Feel free to contact for any query or suggestion reagrding the project. <br>
> tanvirrobin18@cse.pstu.ac.bd <br>
> Telegram: @RooBiiinnn
