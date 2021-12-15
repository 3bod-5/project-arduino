#include <Servo.h>
#define trig 12
#define echo 13
int LDR_sensor = A0;
int sensorValue = 0;
int led = 10;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
long distance, duration;

void setup() {

  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  pinMode(LDR_sensor, INPUT);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  
  digitalWrite(trig, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); 
  distance = (duration/2) / 29.1;
  sensorValue = analogRead(LDR_sensor);
  if (sensorValue <= 300 )
  {
    for (pos = 0; pos < 90; pos += 1) 
       { 
        // goes from 0 degrees to 90 degrees
        // in steps of 1 degree
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15);// waits 15ms for the servo to reach the position 
    }for (pos = 90; pos > 0; pos -= 1) 
       { 
        // goes from 0 degrees to 90 degrees
        // in steps of 1 degree
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15);// waits 15ms for the servo to reach the position 
    }
    if(distance<100){
    Serial.print("distance : ");
    Serial.println(distance);
    digitalWrite(led,HIGH);
    Serial.println(sensorValue);
    Serial.println("its night");
    }
    delay(10000);
  }

  if (sensorValue > 300 && distance >=100)
  {
    digitalWrite(led,LOW);
    Serial.println(sensorValue);
    Serial.println("its daylight");
     delay(10000);
  }
  
}
