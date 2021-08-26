#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//#include <DHT.h>
#include <MQ135.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//DHT dht(2, DHT11);
MQ135 gasSensor = MQ135(0);

int value, co2lvl;

byte N[8] = 
{
B00000,
B01110,
B01010,
B01110,
B00000,
B00000,
B00000,
B00000,
};
  
void setup()
{
  Serial.begin(9600);
//9h  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.createChar (0,N);
}


void loop()
{
  delay(1000);
  lcd.setCursor(0, 0);
  
  lcd.print("A_Q:");
  float ppm = gasSensor.getPPM();
  lcd.print(ppm*100, 0);
  lcd.print("ppm");
  
  //float h = dht.readHumidity();
  //float t = dht.readTemperature();
 
  //if (isnan(h) || isnan(t)) 
 // {
  //  Serial.println("Error obteniendo los datos del sensor DHT11");
  //  return;
 // }
  
  //float hic = dht.computeHeatIndex(t, h, false);

 lcd.setCursor(0,1);
 lcd.print("T:");
 //lcd.print(t, 0);
 lcd.write (byte (0));
 lcd.print("C");
 lcd.print("   H:");
 //lcd.print(h, 1);
 lcd.print("%");
}
