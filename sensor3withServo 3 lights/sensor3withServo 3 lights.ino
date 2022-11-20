//https://www.youtube.com/watch?v=R5V-vUsJZtg
//https://www.youtube.com/watch?v=QXM0crc1hMk&list=PLIwBwnv58nlDQv8zJSUmP7gGv7h86K8ZB&index=25

#include <CapacitiveSensor.h>
#include <Servo.h>

int BluelightPin = 13;
int GreenlightPin = 8;
int OrangelightPin = 7;
int pos = 0;
Servo myservo; 

// create an instance of the library. pin 2 is the sensor
CapacitiveSensor capsense = CapacitiveSensor(4, 2);

void setup() {
  // start serial
  Serial.begin(9600);
  pinMode(BluelightPin, OUTPUT);
  pinMode(GreenlightPin, OUTPUT);
  pinMode(OrangelightPin, OUTPUT);

  myservo.attach(9); // attaches the servo on pin 12 to the servo object
}


void loop() {


  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }  


//------------------------------------------------------------------------------------------------------------
    // store the sense value - argument is number of samples to take
  long val =  capsense.capacitiveSensor(30);

  // if the sensor val is greater than 90 less than 350, turn the LED on
  if(val > 90 && val <230){
    digitalWrite(BluelightPin, HIGH);
    digitalWrite(GreenlightPin, LOW); 
    digitalWrite(OrangelightPin, LOW); 
    for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 60 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }else if(val >230 && val <390){ // greater than 350 less than 700 (two people) turn it off
      digitalWrite(GreenlightPin, HIGH); 
         digitalWrite(BluelightPin, LOW);
             digitalWrite(OrangelightPin, LOW);
        for (pos = 60; pos <= 120; pos += 1) { // goes from 60 degrees to 120 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }  
  }else if(val >390 && val <1050){ // greater than 700 less than 1050 (three people) turn it on
      digitalWrite(OrangelightPin, HIGH); 
          digitalWrite(GreenlightPin, LOW); 
            digitalWrite(BluelightPin, LOW);
        for (pos = 120; pos <= 180; pos += 1) { // goes from 120 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }  
  }else{ // otherwise turn it off
      digitalWrite(GreenlightPin, LOW); 
    digitalWrite(BluelightPin, LOW);
          digitalWrite(OrangelightPin, LOW); 
  }
  
  // print the info to the serial monitor
  Serial.print("capacitive sense value: ");
  Serial.println(val); // print sensor output

  delay(10); 
  

}