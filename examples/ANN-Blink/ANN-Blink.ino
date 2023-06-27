/*In this example, the neural network is trained to predict the next state of the LED (ON or OFF) based on a sequence of input patterns. The loop() function trains the network using a sequence of training inputs and targets, and then tests the network by predicting the next LED state for each input pattern. The LED is toggled based on the prediction result, with a delay of 1 second between each prediction.

Make sure to connect an LED with a current-limiting resistor to pin 13.

Note: Ensure that you have the ANN.h and ANN.cpp files in the same directory as your Arduino sketch or in the Arduino library folder.*/

#include "ANN.h"

// Define the number of nodes for input, hidden, and output layers
const int inputNodes = 1;
const int hiddenNodes = 4;
const int outputNodes = 1;

// Define the learning rate
const float learningRate = 0.05;

// Create an instance of the ANN class
ANN neuralNetwork(inputNodes, hiddenNodes, outputNodes, learningRate);

// LED pin assignment
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Create a sequence of input patterns for training
  float trainingInputs[4][1] = {
    {0},
    {1},
    {0},
    {1}
  };

  // Create a sequence of target patterns for training
  float trainingTargets[4][1] = {
    {1},
    {0},
    {1},
    {0}
  };

  // Train the neural network
  for (int i = 0; i < 4; i++) {
    float *inputs = trainingInputs[i];
    float *targets = trainingTargets[i];
    neuralNetwork.train(inputs, targets);
  }

  // Test the neural network
  for (int i = 0; i < 4; i++) {
    float *inputs = trainingInputs[i];
    float *predicted = neuralNetwork.predict(inputs);

    // Toggle the LED based on the prediction
    digitalWrite(ledPin, predicted[0] > 0.5 ? HIGH : LOW);
    delay(1000);
  }
}
