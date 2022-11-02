#include <DFRobot_DHT20.h> //set pin no of ardinuo to which led is connected
DFRobot_DHT20 dht20;
#define pwm 9


float t=0;
const int ledPin = 8; //redled
const int ledPin2 = 7;//blueled
void setup() {
Serial.begin(115200);
pinMode(ledPin, OUTPUT);//Change to output my pins
pinMode(ledPin2, OUTPUT);
while(dht20.begin()){
    Serial.println("Initialize sensor failed");
    delay(1000);
  }
digitalWrite(ledPin2,LOW);//Turn off LED
digitalWrite(ledPin,LOW);//Turn off LED
  
}
void loop() {
  t = dht20.getTemperature();//temperature value centigrades
  if(t>=25)//if temperature above of specified degrees
    {
      digitalWrite(ledPin,HIGH);//red led activated
      digitalWrite(ledPin2,LOW);
      Serial.print("Red led activated  ");
      analogWrite(pwm,255);//fan speed is increased
     
    }
    else if(t<25)//if temperature is under specified degrees
    {
      digitalWrite(ledPin2,HIGH);
      digitalWrite(ledPin,LOW);//blue led activated
      Serial.print("Blue led activated  ");
      analogWrite(pwm,51);//fan operates on normal rpm
    }
    //Get ambient temperature
  Serial.print("temperature:"); Serial.print(dht20.getTemperature());Serial.print("C  ");
  Serial.println(analogRead(A0));
  delay(1500);
                  
  }
