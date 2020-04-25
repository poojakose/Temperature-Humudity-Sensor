#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11,6, 5, 4, 3);

// Example testing sketch for various DHT humidity/temperature sensors

#define DHTPIN 8    // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
 delay(1000);
  dht.begin();
}

void loop() {

  int h = dht.readHumidity();
  int t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
     lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Failed to read from DHT");
     delay(1000);
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
     delay(1000);
     lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
    lcd.setCursor(5,0);
  lcd.print(t);
    lcd.setCursor(8,0);
  lcd.print("C");
   lcd.setCursor(0,1);
  lcd.print("Humidity: ");
    lcd.setCursor(10,1);
  lcd.print(h); 
  lcd.setCursor(13,1);
  lcd.print("%");
  }
}
