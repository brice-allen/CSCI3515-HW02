#include <Arduino.h>
#define ARRAYSIZE 3
String temps[ARRAYSIZE] = {"Kelvin", "Celcius","Fahrenheit"};
unsigned long int time = millis();
void setup()
{
 Serial.begin(9600);
 

}

void loop()
{
    unsigned long int time = millis();
    size_t temppin = A0;
    size_t reading = analogRead(temppin);
    double thermoresist = 10000.0 * ((1024.0 / reading - 1));
    double logofthermoresist = log(thermoresist);
    double tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * logofthermoresist * logofthermoresist)) * logofthermoresist);
    float tempC = tempK - 273.15;
    float tempF = (tempC * 9.0) / 5.0 + 32.0;
    
    Serial.println("-----------------");
    Serial.print("Elapsed time in milliseconds: ");
        Serial.println(time);
    Serial.println("-----------------");
    Serial.print("Kelvin: ");
        Serial.println(tempK);
    Serial.print("Celcius: ");
        Serial.println(tempC);
    Serial.print("Fahrenheit: ");
        Serial.println(tempF);

    delay(1000);
}