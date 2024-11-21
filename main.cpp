#include <Arduino.h>
#include "Thermistor.h"

// Initialisation des paramètres de la thermistance
double Rref = 1000;        // Résistance de référence à T0 (en ohms)
double R0 = 1500;          // Résistance fixe dans le pont diviseur (en ohms)
double Beta = 3275;        // Coefficient Beta
unsigned samplingBits = 10; // Résolution ADC en bits
double Vcc = 5.0;          // Tension d'alimentation (en volts)
double T0 = 298.15;        // Température de référence en Kelvin (25°C)

// Création de l'objet Thermistor
Thermistor thermistor(Rref, R0, Beta, samplingBits, Vcc, T0);

void setup() {
    // Initialisation du port série
    Serial.begin(9600);
    Serial.println("Thermistor Temperature Measurement");
}

void loop() {
    // Lire la valeur ADC à partir de la broche A0
    int adcValue = analogRead(A0);

    // Convertir la valeur ADC en température
    double temperatureCelsius = thermistor.getTemperature(static_cast<double>(adcValue), 'C');

    // Afficher la température en °C
    Serial.print("Température mesurée : ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");

    // Attendre 5 secondes avant de refaire une mesure
    delay(5000);
}
