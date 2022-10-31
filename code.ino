#include <DFRobot_DHT20.h> //set pin no of ardinuo to which led is connected
DFRobot_DHT20 dht20;
#define pwm 9


boolean a=LOW,b=HIGH;
float h=0,t=0;
const int ledPin = 8; //LED pins for temperature control 
const int ledPin2 = 7;

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

// the loop function runs over and over again forever
void loop() {
  h = dht20.getHumidity();//humidity value
  t = dht20.getTemperature();//temperature value centigrades if you want farenheit change to
  //t = dht.readTemperature(true);
  if(t>=25 && a==LOW)//if temperature above of 25 degrees
    {
      digitalWrite(ledPin,HIGH);//Active air conditioner
      digitalWrite(ledPin2,LOW);
      analogWrite(pwm,102);
      a=HIGH;
      b=LOW;
     
    }
    else if(t<=23&&b==LOW)//if temperature is under 23 degrees
    {
      digitalWrite(ledPin2,HIGH);
      digitalWrite(ledPin,LOW);//Turn off air conditioner
      analogWrite(pwm,51);
      a=LOW;
      b=HIGH;
    }
    //Get ambient temperature
  Serial.print("temperature:"); Serial.print(dht20.getTemperature());Serial.print("C");
  //Get relative humidity
  Serial.print("  humidity:"); Serial.print(dht20.getHumidity()*100);Serial.println(" %RH");
 
  Serial.println(analogRead(A0));
delay(500);

 
  

  delay(1000);
                  
  }
