int matlabData;
#define trigPin 11
#define echoPin 12
#define buzzer 3
int ultrasono(int duration, int distance);
long distance,duration;
int led = 4;
int led1 = 5;
int led2 = 6;
int led3 = 7;
int sound = 250;
int pir=2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin (9600);
 }

 void loop() 
 {
 /*digitalWrite(ledPin,LOW);
 delay(3000);
    int value=digitalRead(pir);
    if(value==HIGH)
    {
      digitalWrite(ledPin,HIGH);
      delay(30000);
      digitalWrite(ledPin,LOW);
    }
    else
    digitalWrite(ledPin,LOW);*/
    distance=ultrasono(duration,distance);
    if(distance <= 10)
    {
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    }
    else if(distance >10 && distance <=25)
    {
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    }
    else
    {
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    }
    while(Serial.available()> 0)
    {
    matlabData=Serial.read(); // read data
    if(matlabData==123)
    {
    digitalWrite(led,HIGH); // turn green light on
    digitalWrite(led1, LOW); // turn red light off
    digitalWrite(buzzer,LOW);
    /*noTone(buzzer);*/
    /*distance1=ultrasono1(duration1,distance1);
    if(distance <= 20)
    digitalWrite(led, HIGH);
    else
    digitalWrite(led, LOW);*/
    }
    else if(matlabData!=123 && matlabData!=9)
    {
    digitalWrite(led1, HIGH); // turn red light on
    digitalWrite(led,LOW);    // turn green led off
    digitalWrite(buzzer,HIGH);
    //sound = 250;
    } 
    else if(matlabData==9)
    {
      digitalWrite(led,LOW);
      /*digitalWrite(led1,LOW);  
      digitalWrite(led2,LOW);  
      digitalWrite(led3,LOW);  
      digitalWrite(buzzer,LOW);*/              
    }
 } 
 }   
  

int ultrasono(long duration, long distance)
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

