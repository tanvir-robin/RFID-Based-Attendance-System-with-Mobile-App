#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define NTP_OFFSET 60 * 60      // In seconds
#define NTP_INTERVAL 60 * 1000  // In miliseconds
#define NTP_ADDRESS "europe.pool.ntp.org"


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, 6*NTP_OFFSET, NTP_INTERVAL);


// Set these to run example.
#define FIREBASE_HOST "YOUR_REALTIME_DATABASE_HOST"
#define FIREBASE_AUTH "FIREBASE_AUTH_KEY"
#define WIFI_SSID "WIFI_SSID"   // define WIFI SSID
#define WIFI_PASSWORD "WIFI_PASSWORD"  // Define WIFI Password

void setup() {
  Serial.begin(9600);
  timeClient.begin();
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
}

int n = 0;

void loop() {
  timeClient.update();


  if (Serial.available()) {
    String formattedTime = timeClient.getFormattedTime();
   // String path = String(n)+"/"+formattedTime+String(random(1,500));
    String path = String(n);
    String receivedData = Serial.readStringUntil('\n');
    Serial.println("Received: " + receivedData);
    if (receivedData[0] == '!') {
      String cardVal = receivedData.substring(2);
      Serial.println(cardVal);

      Firebase.setString(path + "/RFID", cardVal);
      Firebase.setString(path + "/Permission", "Denied");
      Firebase.setString(path + "/time", formattedTime);
      Firebase.setInt("number", n++);
    } else if((receivedData[2]<='Z' && receivedData[2]>='A') || (receivedData[2]<='9' && receivedData[2]>='0')) {
      Firebase.setString(path + "/RFID", receivedData);
      Firebase.setString(path + "/Permission", "Granted");
      Firebase.setString(path + "/time", formattedTime);
      Firebase.setInt("number", n++);
    }
    // handle error
    if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());
      return;
    }
    delay(1000);
  }

}
