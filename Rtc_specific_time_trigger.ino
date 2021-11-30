
#include <RTClib.h> // for the RTC

// Instance of the class for RTC
RTC_DS1307 rtc;

// Define check in time
const int ONHour1 = 18;
const int ONMinute1 =00;
const int OFFHour1 = 22;
const int OFFMinute1 = 00;
//////////////////////////////////
const int ONHour2 = 04;
const int ONMinute2 =00;
const int OFFHour2 = 06;
const int OFFMinute2 = 00;


int CurrentHour;
int CurrentMinute;
// Pins for LEDs and buzzer

const int relay1 = 2;
const int relay2 = 3;



void setup() {
  Serial.begin(9600);
  rtc.begin();
   pinMode(relay1, OUTPUT);
   pinMode(relay2, OUTPUT);   
 
}
void loop() {
 DateTime now = rtc.now();
   // Save check in time;
    CurrentHour = now.hour();
    CurrentMinute = now.minute();
  Serial.println(CurrentHour);
  Serial.println(CurrentMinute);
  if((CurrentHour==ONHour1) && (CurrentMinute == ONMinute1)){
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,HIGH);
    Serial.println("LIGHT ON");
    }
if((CurrentHour==OFFHour1) && (CurrentMinute == OFFMinute1)){
      digitalWrite(relay1,LOW);
       digitalWrite(relay2,LOW);
      Serial.println("LIGHT OFF");
    }
      if((CurrentHour==ONHour2) && (CurrentMinute == ONMinute2)){
    digitalWrite(relay2,HIGH);
    digitalWrite(relay1,HIGH);
    Serial.println("LIGHT ON");
    }
if((CurrentHour==OFFHour2) && (CurrentMinute == OFFMinute2)){
      digitalWrite(relay2,LOW);
       digitalWrite(relay1,LOW);
      Serial.println("LIGHT OFF");
    }
}
