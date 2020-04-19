#include <Servo.h>          
 
Servo servo_right;        
Servo servo_left;  

const int trigPin = 13;
const int echoPin = 12;
long duration;
int distance;


int led = 2;           


int angle = 0;    
 
void setup() 
{ 
servo_right.attach(7);      
servo_left.attach(4); 

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
Serial.begin(9600);

pinMode(led, OUTPUT);
} 
  
void loop() 
{
///////////////////////////////////////////////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(200);

////////////////////////////////////////// State 2 /////////////////////////////////////////////////////







if (distance>10)

{
                                
    servo_right.write(120);                
  servo_left.write(60);  

 digitalWrite(led, LOW);   
    
  
 
 
}
////////////////////////////////////////// State 3 /////////////////////////////////////////////////////


else if (distance<10)

{
     
    digitalWrite(led, HIGH);                               
    servo_right.write(10);                
  servo_left.write(170);  


    
  
 
 
}



}
