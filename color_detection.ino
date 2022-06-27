#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);
int frequency = 0;
int frequency0 = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  display.clearDisplay(); // clear display

   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.display();
   display.clearDisplay();
   display.setFont(&FreeSans9pt7b);
  display.setCursor(0,0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 25, 72, 255, 0);
  Serial.print("R = ");
  Serial.println(frequency);
  if (frequency >= 230) {
    display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 25);
    display.println("RED");
  display.display();   
  }
  else{
        display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 25);
    display.println("no color");
  display.display();  
    }


  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency0 = pulseIn(sensorOut, LOW);
  frequency0 = map(frequency, 25,70,255,0);
    Serial.print("B = ");
  Serial.println(frequency);
  if (frequency0 >= 230) {
    display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 25);
  display.println("BLUE");
  display.display();     
  }
    else{
        display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 25);
    display.println("no color");
  display.display();  
    }
}
