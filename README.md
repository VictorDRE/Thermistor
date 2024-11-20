# Thermistor Library

## Description
This library provides tools to measure temperature using a thermistor and an Arduino board.

## Author
- Name: DREYER Victor
- Email: victor.dreyer02@gmail.com
- Date: 2024-11-18

## Usage
- Include the library in your project.
- Initialize a Thermistor object with your specific parameters (Rref, R0, Beta, etc.).
- Use the `getTemperature` function to measure the temperature in Kelvin, Celsius, or Fahrenheit.

## Example
See the `examples/simpleTest` folder for a sample implementation.

## Schematic
- A thermistor is connected in series with a fixed resistor.
- The middle point is connected to an ADC pin.
