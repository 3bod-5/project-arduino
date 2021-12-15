#define IN1 9
#define IN2 8

int motor_speed = 0;


void setup()
{
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2


  
  Serial.begin(9600); 
}

void loop()
{
  
  Serial.println("turning");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

}}
