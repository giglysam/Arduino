const int ledpin = 13;
const int flamepin = A4;
const int threshold = 80;
int flamesensvalue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(flamepin, INPUT);
}
void loop() {
  flamesensvalue = analogRead(flamepin);
  Serial.println(flamesensvalue);
  if (flamesensvalue <= threshold) {
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }
}
