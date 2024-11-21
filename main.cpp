#include <Arduino.h>
#include "Thermistor.h"

// Configuration for the thermistor
const double referenceResistance = 1000.0;    // Resistance at reference temperature (Ohms)
const double fixedResistance = 1500.0;       // Fixed resistor value in the voltage divider (Ohms)
const double betaCoefficient = 3275.0;       // Beta coefficient of the thermistor
const unsigned adcResolution = 10;           // ADC resolution in bits (10 bits for Arduino UNO)
const double supplyVoltage = 5.0;            // Supply voltage (Volts)
const double referenceTemperature = 298.15;  // Reference temperature (Kelvin, typically 25°C)

// Create a Thermistor object
Thermistor thermistor(referenceResistance, fixedResistance, betaCoefficient, 
                      adcResolution, supplyVoltage, referenceTemperature);

void setup() {
    // Initialize the serial monitor
    Serial.begin(9600);
    Serial.println("Thermistor Library Test");
    Serial.println("------------------------");
}

void loop() {
    // Read the ADC value from analog pin A0
    int adcValue = analogRead(A0);

    // Convert ADC value to temperature in Celsius
    double temperatureCelsius = thermistor.getTemperature(static_cast<double>(adcValue), 'C');

    // Print the temperature to the serial monitor
    Serial.print("Measured Temperature: ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");

    // Wait 5 seconds before the next measurement
    delay(5000);
}
