int buzzer = 13;
int trigPin = 12;
int echoPin = 11;

void setup() {
     pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  delay(10);


   if (distance < 25) {
    tone(buzzer, 800);
    delay(50);
    
   }
  else if (distance > 20){
    noTone(buzzer);
    }
  
}
