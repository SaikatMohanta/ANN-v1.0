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
