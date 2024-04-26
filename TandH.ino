
#include<Arduino.h>
#include<LiquidCrystal.h>
#include<DHT.h>

const int DHTPIN=7;
int DHTTYPE=DHT22;

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,  en, d4, d5, d6, d7);
 DHT dht(DHTPIN, DHTTYPE);

 
void setup() 
{
  dht.begin();
  lcd.begin(16, 2);
float h=dht.readHumidity();
float t=dht.readTemperature();

 lcd.setCursor(0, 0);
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
