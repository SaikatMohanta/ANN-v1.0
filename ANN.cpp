#include "ANN.h"

ANN::ANN(int inputNodes, int hiddenNodes, int outputNodes, float learningRate) {
  this->inputNodes = inputNodes;
  this->hiddenNodes = hiddenNodes;
  this->outputNodes = outputNodes;
  this->learningRate = learningRate;
/*This line assigns the value of the inputNodes parameter passed to the 
  constructor to the inputNodes member variable of the ANN class. The this-> syntax is used to distinguish between the local parameter and the member variable with 
  the same name. By assigning the constructor parameters to the corresponding member variables, the values provided when creating an instance of the ANN class are stored 
  within the object. These member variables can then be accessed and used throughout the class implementation as needed. Note that the this pointer is used here to 
  disambiguate between the parameter and the member variable with the same name. It ensures that the assignment is made to the correct variable in the class scope.*/
  inputWeights = new float[inputNodes * hiddenNodes];
  hiddenWeights = new float[hiddenNodes * outputNodes];
  hiddenBiases = new float[hiddenNodes];
  outputBiases = new float[outputNodes];
  hiddenOutputs = new float[hiddenNodes];
  finalOutputs = new float[outputNodes];

  initializeWeights();
}

void ANN::initializeWeights() {
  for (int i = 0; i < inputNodes * hiddenNodes; i++) {
    inputWeights[i] = random(-1, 1);
  }

  for (int i = 0; i < hiddenNodes * outputNodes; i++) {
    hiddenWeights[i] = random(-1, 1);
  }

  for (int i = 0; i < hiddenNodes; i++) {
    hiddenBiases[i] = random(-1, 1);
  }

  for (int i = 0; i < outputNodes; i++) {
    outputBiases[i] = random(-1, 1);
  }
}

float ANN::sigmoid(float x) {
  return 1 / (1 + exp(-x));
}

float* ANN::predict(float *inputs) {
  return forwardPropagation(inputs);
}

float* ANN::forwardPropagation(float *inputs) {
  for (int i = 0; i < hiddenNodes; i++) {
    float sum = 0;
    for (int j = 0; j < inputNodes; j++) {
      sum += inputs[j] * inputWeights[j * hiddenNodes + i];
    }
    hiddenOutputs[i] = sigmoid(sum + hiddenBiases[i]);
  }

  for (int i = 0; i < outputNodes; i++) {
    float sum = 0;
    for (int j = 0; j < hiddenNodes; j++) {
      sum += hiddenOutputs[j] * hiddenWeights[j * outputNodes + i];
    }
    finalOutputs[i] = sigmoid(sum + outputBiases[i]);
  }

  return finalOutputs;
}

void ANN::backwardPropagation(float *inputs, float *targets, float *outputs) {
  float outputErrors[outputNodes];
  for (int i = 0; i < outputNodes; i++) {
    float outputError = targets[i] - outputs[i];
    outputErrors[i] = outputError * outputs[i] * (1 - outputs[i]);
  }

  float hiddenErrors[hiddenNodes];
  for (int i = 0; i < hiddenNodes; i++) {
    float error = 0;
    for (int j = 0; j < outputNodes; j++) {
      error += outputErrors[j] * hiddenWeights[i * outputNodes + j];
    }
    hiddenErrors[i] = error * hiddenOutputs[i] * (1 - hiddenOutputs[i]);
  }

  for (int i = 0; i < hiddenNodes; i++) {
    for (int j = 0; j < outputNodes; j++) {
      hiddenWeights[i * outputNodes + j] += learningRate * outputErrors[j] * hiddenOutputs[i];
    }
  }

  for (int i = 0; i < inputNodes; i++) {
    for (int j = 0; j < hiddenNodes; j++) {
      inputWeights[i * hiddenNodes + j] += learningRate * hiddenErrors[j] * inputs[i];
    }
  }

  for (int i = 0; i < outputNodes; i++) {
    outputBiases[i] += learningRate * outputErrors[i];
  }

  for (int i = 0; i < hiddenNodes; i++) {
    hiddenBiases[i] += learningRate * hiddenErrors[i];
  }
}

void ANN::train(float *inputs, float *targets) {
  float *outputs = forwardPropagation(inputs);
  backwardPropagation(inputs, targets, outputs);
}
