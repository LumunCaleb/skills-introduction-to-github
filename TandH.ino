//Code to read Temperature and Humidity values from DHT22 Sensor module

//Include necessary libraries
#include<Arduino.h>         //Arduino library
#include<LiquidCrystal.h>   //LCD display library
#include<DHT.h>             //DHT sensor library

const int DHTPIN=7;        //Define DHT data pin. Conected to arduino digital pin7
int DHTTYPE=DHT22;         //Define DHT semsor type: DHT22


const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;  //Assign arduino pins for LCD connection 
LiquidCrystal lcd(rs,  en, d4, d5, d6, d7);     //Using half duplex communication: data pins
 DHT dht(DHTPIN, DHTTYPE);                      

 
void setup() 
{
 //Initialize and assign variables
  dht.begin();
  lcd.begin(16, 2);
float h=dht.readHumidity();
float t=dht.readTemperature();

 lcd.setCursor(0, 0);  //Set cursor on row 0, column 0
  lcd.print("MOBILE FARMING");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM");
  delay(50);

}

void loop() 
{
  float h=dht.readHumidity();
  float t=dht.readTemperature();
 if (isnan(t)||isnan(h))
 {
  lcd.setCursor(0, 0);
  lcd.print("Error; DHT11 reading");
 }
 else
 {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity:");
    lcd.print(h);
    lcd.print("%"); }


    lcd.setCursor(0,1);
    lcd.print("Temp.:");
    lcd.print(t);
    lcd.print(" Degrees.");
//delay(1000);
}
