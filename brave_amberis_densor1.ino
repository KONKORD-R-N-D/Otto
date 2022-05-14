#include <Servo.h>

int servoPin1 = 6;
int servoPin2 = 3;
int servoPin3 = 9;
int servoPin4 = 5;
int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
//создать объект
 Servo Servo1, Servo2, Servo3, Servo4;

void moonwalker()
{
  Servo1.write(90);
  delay(1000);
  Servo2.write(90);
  delay(1000);
  Servo3.write(90);
  delay(1000);
  Servo4.write(90);
  delay(1000);
  
  Servo1.write(0);
  delay(1000);
  Servo2.write(0);
  delay(1000);
  Servo3.write(0);
  delay(1000);
  Servo4.write(0);
  delay(1000);
}

void dim()
{
    digitalWrite(trigPin,LOW); 
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin,LOW); 
  pingTravelTime = pulseIn(echoPin,HIGH); 
  delay(25); 
  Serial.println(pingTravelTime); 
}
  
void position()
{
  Servo1.write(90);
  delay(1000);
  Servo2.write(90);
  delay(1000);
  Servo3.write(90);
  delay(1000);
  Servo4.write(90);
  delay(1000);
}

void setup() 
{
  //Подключить сервопривод к нужному номеру пина
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Servo4.attach(servoPin4);
  pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    Serial.begin(9600);
  position();
}

void loop()
{
dim();
  if (pingTravelTime > 2000 && pingTravelTime < 2500)
  {
   moonwalker();
  }
}

