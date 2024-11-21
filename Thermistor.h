#ifndef THERMISTOR_H
#define THERMISTOR_H

// Constant for Celsius to Kelvin conversion
const double ZERO_CELSIUS = 273.15;

/**
 * @class Thermistor
 * @brief A class to calculate the temperature using a thermistor and an ADC.
 */
class Thermistor {
private:
    double referenceResistance;    // Resistance of the thermistor at reference temperature (Ohms)
    double fixedResistance;        // Fixed resistor value in the voltage divider (Ohms)
    double betaCoefficient;        // Beta coefficient of the thermistor
    double referenceTemperature;   // Reference temperature in Kelvin (typically 298.15 K)
    double supplyVoltage;          // Voltage supply for the circuit (Volts)
    unsigned adcResolution;        // Resolution of the ADC (in bits, e.g., 10 bits for Arduino UNO)

public:
    /**
     * @brief Constructor to initialize the Thermistor class.
     * @param referenceResistance Resistance of the thermistor at the reference temperature.
     * @param fixedResistance Fixed resistor value in the voltage divider.
     * @param betaCoefficient Beta coefficient of the thermistor.
     * @param adcResolution ADC resolution (in bits, e.g., 10 bits).
     * @param supplyVoltage Supply voltage for the circuit (default is 5.0 V).
     * @param referenceTemperature Reference temperature in Kelvin (default is 298.15 K).
     */
    Thermistor(double referenceResistance, double fixedResistance, double betaCoefficient, 
               unsigned adcResolution = 10, double supplyVoltage = 5.0, 
               double referenceTemperature = 298.15);

    /**
     * @brief Calculate the temperature from the ADC value.
     * @param adc ADC value (numeric value from 0 to 2^resolution - 1).
     * @param unit Unit of the temperature: 'K' for Kelvin, 'C' for Celsius, 'F' for Fahrenheit.
     * @return The calculated temperature in the specified unit.
     */
    double getTemperature(double adc, char unit = 'K');
};

#endif // THERMISTOR_H
