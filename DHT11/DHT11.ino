#include <LiquidCrystal.h>
#include <DHT.h>
#include "DHT.h"
#define DHTPIN A0     // what pin we're connected to
#define DHTTYPE DHT11   // we are using the DHT11 sensor
int soundSensor = 6; //connecting the sound sensor 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //LiquidCrystal(rs, enable, d4, d5, d6, d7)
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  for (int DigitalPin = 7; DigitalPin <= 10; DigitalPin++) 
   {
      pinMode(DigitalPin, OUTPUT);
   }
  lcd.begin(16,2);  //16 by 2 character display
  dht.begin();
  pinMode (soundSensor, INPUT);
}

 
void loop()
{
  delay(1000);
  
  // ****** Reading temperature or humidity takes about 250 milliseconds!**********
  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);  //printing temperarture to the LCD display
  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);  //printing humidity to the LCD display
  lcd.print("%");
  
//************** Temp 3-led setup process ************
  if (t<=22)
    {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    }
  else if (t>=35)
    {
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
    }
  else 
    {
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    }
    
  // ************ Sound detection ********************* 
  int statusSensor = digitalRead (soundSensor);
    if (statusSensor == 1)
      {
        digitalWrite(7, HIGH);
      }
    else
      {
        digitalWrite(7, LOW);
      } 
}
