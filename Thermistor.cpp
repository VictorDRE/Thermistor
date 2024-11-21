#include "Thermistor.h"
#include <math.h> // For mathematical functions like log and pow

// Constructor
Thermistor::Thermistor(double referenceResistance, double fixedResistance, double betaCoefficient, 
                       unsigned adcResolution, double supplyVoltage, double referenceTemperature)
    : referenceResistance(referenceResistance), fixedResistance(fixedResistance), 
      betaCoefficient(betaCoefficient), adcResolution(adcResolution), 
      supplyVoltage(supplyVoltage), referenceTemperature(referenceTemperature) {}

// Method to calculate temperature
double Thermistor::getTemperature(double adc, char unit) {
    // Step 1: Convert ADC value to voltage
    double voltageOut = (adc / (pow(2.0, adcResolution) - 1.0)) * supplyVoltage;

    // Step 2: Calculate the resistance of the thermistor (Rt)
    double thermistorResistance = fixedResistance * (supplyVoltage / voltageOut - 1.0);

    // Step 3: Calculate the temperature in Kelvin
    double temperatureKelvin = 1.0 / (1.0 / referenceTemperature + 
                                      (1.0 / betaCoefficient) * log(thermistorResistance / referenceResistance));

    // Step 4: Convert the temperature to the requested unit
    switch (unit) {
        case 'C': // Celsius
            return temperatureKelvin - ZERO_CELSIUS;
        case 'F': // Fahrenheit
            return (temperatureKelvin - ZERO_CELSIUS) * 9.0 / 5.0 + 32.0;
        case 'K': // Kelvin
        default:
            return temperatureKelvin;
    }
}
