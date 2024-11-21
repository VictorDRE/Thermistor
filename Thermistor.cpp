#include "Thermistor.h"
#include <math.h> // Utilisation de math.h pour les calculs de log et pow

// Constructeur
Thermistor::Thermistor(double Rref, double R0, double Beta, unsigned samplingBitsNumber, double Vcc, double T0)
    : Rref(Rref), R0(R0), Beta(Beta), samplingBitsNumber(samplingBitsNumber), Vcc(Vcc), T0(T0) {}

// Méthode pour calculer la température
double Thermistor::getTemperature(double adc, char unit) {
    // Étape 1 : Conversion de la valeur ADC en tension
    double Vout = (adc / (pow(2.0, samplingBitsNumber) - 1.0)) * Vcc;

    // Étape 2 : Calcul de la résistance de la thermistance (Rt)
    double Rt = R0 * (Vcc / Vout - 1.0);

    // Étape 3 : Calcul de la température en Kelvin
    double temperatureKelvin = 1.0 / (1.0 / T0 + (1.0 / Beta) * log(Rt / Rref));

    // Étape 4 : Conversion selon l'unité demandée
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
