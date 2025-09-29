#include <EEPROM.h>;
int Dir;
int Count;

void setup()
{
  Serial.begin(9600);
  Count = EEPROM.read(Dir);
  Count++;
  EEPROM.write(Dir,Count);
  Serial.println(Count);
}

void loop()
{
  
}