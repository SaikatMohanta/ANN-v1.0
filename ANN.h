#ifndef ANN_h
#define ANN_h

#include <Arduino.h>

class ANN {
  public:
    ANN(int inputNodes, int hiddenNodes, int outputNodes, float learningRate);
    void train(float *inputs, float *targets);
    float* predict(float *inputs);

  private:
    int inputNodes;
    int hiddenNodes;
    int outputNodes;
    float learningRate;

    float *inputWeights;
    float *hiddenWeights;
    float *hiddenBiases;
    float *outputBiases;
    float *hiddenOutputs;
    float *finalOutputs;

    void initializeWeights();
    float sigmoid(float x);
    float* forwardPropagation(float *inputs);
    void backwardPropagation(float *inputs, float *targets, float *outputs);
};

#endif
/*The train function is used to perform a training iteration. It executes the forward propagation to obtain the outputs, and then performs backward propagation 
to update the weights and biases based on the provided inputs and target outputs. 

The backwardPropagation function is responsible for updating the weights and biases of the neural network based on the errors between the target outputs and the 
actual outputs. It calculates the errors in the output layer and hidden layer, and then adjusts the weights and biases accordingly.

The forwardPropagation function performs the forward propagation step of the neural network. It calculates the outputs of the hidden layer and the final outputs
based on the provided inputs and the current weights and biases. It returns the final outputs.

The predict function takes an array of input values, performs forward propagation using these inputs, and returns the final outputs of the neural network.

The sigmoid function applies the sigmoid activation function to the given input value x and returns the result. The sigmoid function maps any real number to a
value between 0 and 1.

The initializeWeights function is used to set random values for the input weights, hidden weights, hidden biases, and output biases. The random values are 
generated within the range of -1 to 1.

The constructor of the ANN class. It takes input parameters such as the number of input nodes, hidden nodes, output nodes, and learning rate. It initializes the 
member variables and dynamically allocates memory for the arrays used in the neural network. Finally, it calls the initializeWeights function to initialize the 
weights and biases.*/

