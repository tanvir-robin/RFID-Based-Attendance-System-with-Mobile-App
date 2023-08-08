#include <SoftwareSerial.h>

SoftwareSerial esp8266(2, 3);  // RX, TX

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN A5

MFRC522 rfid(SS_PIN, RST_PIN);
Servo servo;

// My authorized RFID Tags
byte authorizedUID1[4] = { 0xC1, 0xBE, 0x9A, 0x1C };
byte authorizedUID2[4] = { 0x23, 0xE6, 0x9E, 0xE5 };
byte authorizedUID3[4] = { 0xB3, 0xA2, 0x12, 0xE6 };
byte authorizedUID4[4] = { 0x63, 0xE6, 0x34, 0xE6 };
byte authorizedUID5[4] = { 0xF3, 0xEC, 0xDE, 0xE5 };
byte authorizedUID6[4] = { 0x73, 0x70, 0x93, 0xE5 };
byte authorizedUID7[4] = { 0xF3, 0xEC, 0xDE, 0xE5 };

int angle = 0;  // the current angle of servo motor

void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  esp8266.begin(9600);
  SPI.begin();      // init SPI bus
  rfid.PCD_Init();  // init MFRC522
  servo.attach(SERVO_PIN);
  servo.write(angle);  // rotate servo motor to 0°
  pinMode(7, OUTPUT);
  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) {  // new tag is available
    if (rfid.PICC_ReadCardSerial()) {  // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.println("Card found");
      if (rfid.uid.uidByte[0] == authorizedUID1[0] && rfid.uid.uidByte[1] == authorizedUID1[1] && rfid.uid.uidByte[2] == authorizedUID1[2] && rfid.uid.uidByte[3] == authorizedUID1[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        // esp8266.println("Authorized Tag 1");
        changeServo();
        delay(2000);
        changeServo();
      } else if (rfid.uid.uidByte[0] == authorizedUID2[0] && rfid.uid.uidByte[1] == authorizedUID2[1] && rfid.uid.uidByte[2] == authorizedUID2[2] && rfid.uid.uidByte[3] == authorizedUID2[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        //   esp8266.println("Authorized Tag 2");

        changeServo();
        delay(2000);
        changeServo();
      } else if (rfid.uid.uidByte[0] == authorizedUID3[0] && rfid.uid.uidByte[1] == authorizedUID3[1] && rfid.uid.uidByte[2] == authorizedUID3[2] && rfid.uid.uidByte[3] == authorizedUID3[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        // esp8266.println("Authorized Tag 3");

        changeServo();
        delay(2000);
        changeServo();
      } else if (rfid.uid.uidByte[0] == authorizedUID4[0] && rfid.uid.uidByte[1] == authorizedUID4[1] && rfid.uid.uidByte[2] == authorizedUID4[2] && rfid.uid.uidByte[3] == authorizedUID4[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        //  esp8266.println("Authorized Tag 4");

        changeServo();
        delay(2000);
        changeServo();
      } else if (rfid.uid.uidByte[0] == authorizedUID5[0] && rfid.uid.uidByte[1] == authorizedUID5[1] && rfid.uid.uidByte[2] == authorizedUID5[2] && rfid.uid.uidByte[3] == authorizedUID5[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        //  esp8266.println("Authorized Tag 5");

        changeServo();
        delay(2000);
        changeServo();
      } else if (rfid.uid.uidByte[0] == authorizedUID6[0] && rfid.uid.uidByte[1] == authorizedUID6[1] && rfid.uid.uidByte[2] == authorizedUID6[2] && rfid.uid.uidByte[3] == authorizedUID6[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        //  esp8266.println("Authorized Tag 6");

        changeServo();
        delay(2000);
        changeServo();
      } else if (rfid.uid.uidByte[0] == authorizedUID7[0] && rfid.uid.uidByte[1] == authorizedUID7[1] && rfid.uid.uidByte[2] == authorizedUID7[2] && rfid.uid.uidByte[3] == authorizedUID7[3]) {

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }
        esp8266.println();
        // esp8266.println("Authorized Tag 7");

        changeServo();
        delay(2000);
        changeServo();
      } else {
        digitalWrite(7, HIGH);

        esp8266.print("!");

        for (int i = 0; i < rfid.uid.size; i++) {
          esp8266.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          esp8266.print(rfid.uid.uidByte[i], HEX);
        }

        Serial.println();
        delay(500);
        digitalWrite(7, LOW);
      }

      rfid.PICC_HaltA();       // halt PICC
      rfid.PCD_StopCrypto1();  // stop encryption on PCD
    }
  }
}

void changeServo() {
  // change angle of servo motor
  if (angle == 0)
    angle = 180;
  else  //if(angle == 90)
    angle = 0;

  // control servo motor arccoding to the angle
  servo.write(angle);
  Serial.print("Rotate Servo Motor to ");
  Serial.print(angle);
  Serial.println("°");
}
