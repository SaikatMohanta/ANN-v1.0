/*In this example, we incorporate the ANN library into a code that reads the state of a button connected to pin 2 and toggles the LED on pin 13 based on the prediction made by the neural network. When the button is pressed, the code makes a prediction by passing the current button state and the previous button state as inputs to the neural network. If the prediction output is above 0.5, it sets the LED to HIGH; otherwise, it sets the LED to LOW.

Make sure to connect the button between pin 2 and ground (GND) and connect an LED with a current-limiting resistor to pin 13.

Note: Ensure that you have the ANN.h and ANN.cpp files in the same directory as your Arduino sketch or in the Arduino library folder.*/

#include "ANN.h"

// Define the number of nodes for input, hidden, and output layers
const int inputNodes = 2;
const int hiddenNodes = 4;
const int outputNodes = 1;

// Define the learning rate
const float learningRate = 0.05;

// Create an instance of the ANN class
ANN neuralNetwork(inputNodes, hiddenNodes, outputNodes, learningRate);

// Button and LED pin assignments
const int buttonPin = 2;
const int ledPin = 13;

// Variables to store button state and prediction result
int buttonState = 0;
int lastButtonState = 0;
bool prediction = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    delay(10); // debounce delay
    if (buttonState == HIGH) {
      // Button is pressed, make a prediction
      float inputs[] = {float(buttonState), float(lastButtonState)};
      float *predicted = neuralNetwork.predict(inputs);

      // Check the prediction result
      prediction = predicted[0] > 0.5;
      
      // Toggle the LED based on the prediction
      digitalWrite(ledPin, prediction ? HIGH : LOW);
    }
  }

  lastButtonState = buttonState;
}
