/*In this example, the temperature controller uses an LM35 temperature sensor connected to pin A0 to read the temperature. The relay is connected to pin 13, which controls the heating or cooling device. The desired temperature is set to 25.0°C, and the temperature threshold is set to 1.0°C.

The loop() function continuously reads the temperature from the sensor, normalizes it between 0 and 1, and trains the neural network using the current temperature as input and the desired temperature as the target. The network then predicts the next temperature, and based on the difference between the predicted temperature and the desired temperature, the relay is turned on or off.

Note: Ensure that you have the ANN.h and ANN.cpp files in the same directory as your Arduino sketch or in the Arduino library folder. Additionally, make sure to properly connect the LM35 temperature sensor and the relay to the Arduino.*/


#include "ANN.h"

// Define the number of nodes for input, hidden, and output layers
const int inputNodes = 1;
const int hiddenNodes = 4;
const int outputNodes = 1;

// Define the learning rate
const float learningRate = 0.05;

// Create an instance of the ANN class
ANN neuralNetwork(inputNodes, hiddenNodes, outputNodes, learningRate);

// Temperature sensor pin assignment
const int temperaturePin = A0;

// Relay pin assignment
const int relayPin = 13;

// Desired temperature and temperature threshold
const float desiredTemperature = 25.0;
const float temperatureThreshold = 1.0;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(temperaturePin, INPUT);
}

void loop() {
  // Read the temperature from the sensor
  float temperature = readTemperature();

  // Normalize the temperature value between 0 and 1
  float normalizedTemperature = mapFloat(temperature, 0, 1023, 0, 1);

  // Create input and target patterns
  float inputs[] = {normalizedTemperature};
  float target[] = {desiredTemperature};

  // Train the neural network
  neuralNetwork.train(inputs, target);

  // Make a prediction for the current temperature
  float *predicted = neuralNetwork.predict(inputs);

  // Check if the predicted temperature is within the desired range
  if (abs(predicted[0] - desiredTemperature) <= temperatureThreshold) {
    // Temperature is within the desired range, turn off the relay
    digitalWrite(relayPin, LOW);
  } else {
    // Temperature is outside the desired range, turn on the relay
    digitalWrite(relayPin, HIGH);
  }
}

float readTemperature() {
  int rawValue = analogRead(temperaturePin);
  float voltage = rawValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0;
  return temperature;
}

float mapFloat(float x, float inMin, float inMax, float outMin, float outMax) {
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}
