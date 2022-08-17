#include <dht_nonblocking.h>


#include <LiquidCrystal_74HC595.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

namespace lcdPins
{
  constexpr int RS{1};
  constexpr int ENABLE{3};
  constexpr int D4{4};
  constexpr int D5{5};
  constexpr int D6{6};
  constexpr int D7{7};
}

namespace registerPins
{
  constexpr int DS{11};
  constexpr int STCP{12};
  constexpr int SHCP{13};
  constexpr int ENABLE{8};
}


constexpr int dht_pin = 7;

DHT_nonblocking dht{dht_pin, DHT_SENSOR_TYPE};

LiquidCrystal_74HC595 lcd{registerPins::DS, registerPins::SHCP, registerPins::STCP, lcdPins::RS, lcdPins::ENABLE, lcdPins::D4, lcdPins::D5, lcdPins::D6, lcdPins::D7};

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16, 2);
  lcd.print("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity;
  float temp;

  dht.measure(&temp, &humidity);

  lcd.setCursor(0, 0);
 
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
  

   delay(1000);
  
 
}
