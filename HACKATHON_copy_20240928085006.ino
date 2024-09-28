#include <Servo.h>
Servo myServo;
int pos = 0;  
#include<DHT.h>
#define DHTPIN_A   10
#define DHTPIN_B   11
#define DHTPIN_C   12
const int led1=6,led2=7,led3=8,buzz=4;
const float temp=25.;
DHT dht_A(DHTPIN_A, DHT11); 
DHT dht_B(DHTPIN_B, DHT11);
DHT dht_C(DHTPIN_C, DHT11);
void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  dht_A.begin();
  dht_B.begin();
  dht_C.begin();
  myServo.attach(9);
  myServo.write(90);
  delay(1000);  
  Serial.begin(9600);
}
void loop() {
  float t1=dht_A.readTemperature();
  float t2=dht_B.readTemperature(); 
  float t3=dht_C.readTemperature(); 
Serial.println("temperature sensor 1:");
Serial.println(t1);
Serial.println("temperature sensor 2:");
Serial.println(t2);
Serial.println("temperature sensor 3:");
Serial.println(t3);
delay(1000);
if(t1<temp && t2<temp && t3<temp)
{
  digitalWrite(5,LOW);
}
else
{
  digitalWrite(5,HIGH);

}
if(t1>t2 && t1>t3)
{
  myServo.write(160);
}
else if(t2>t1 && t2>t3)
{
  myServo.write(90);
}
else if(t3>t1 && t3>t2)
{
  myServo.write(40);
}
}
