#ifndef THERMISTOR_H
#define THERMISTOR_H

// Constante pour la conversion Celsius <-> Kelvin
const double ZERO_CELSIUS = 273.15;

/**
 * @brief Classe Thermistor : Gère les calculs de température à partir d'une thermistance.
 */
class Thermistor {
private:
    double Rref;               // Résistance à la température de référence (ohms)
    double R0;                 // Résistance fixe dans le pont diviseur (ohms)
    double Beta;               // Coefficient Beta de la thermistance
    double T0;                 // Température de référence (Kelvin, typiquement 298.15K)
    double Vcc;                // Tension d'alimentation (Volts)
    unsigned samplingBitsNumber; // Résolution du convertisseur ADC (en bits)

public:
    /**
     * @brief Constructeur de la classe Thermistor.
     * @param Rref Résistance de la thermistance à la température de référence.
     * @param R0 Résistance fixe utilisée dans le pont diviseur.
     * @param Beta Coefficient Beta de la thermistance.
     * @param samplingBitsNumber Résolution de l'ADC (en bits, ex : 10 pour Arduino UNO).
     * @param Vcc Tension d'alimentation du circuit (par défaut : 5V).
     * @param T0 Température de référence en Kelvin (par défaut : 298.15K).
     */
    Thermistor(double Rref, double R0, double Beta, unsigned samplingBitsNumber = 10, 
               double Vcc = 5.0, double T0 = 298.15);

    /**
     * @brief Calcule la température en fonction de la valeur ADC mesurée.
     * @param adc Valeur numérique obtenue via l'ADC (0 à 1023 pour une résolution de 10 bits).
     * @param unit Unité de la température : 'K' pour Kelvin, 'C' pour Celsius, 'F' pour Fahrenheit.
     * @return Température calculée dans l'unité spécifiée.
     */
    double getTemperature(double adc, char unit = 'K');
};

#endif // THERMISTOR_H
