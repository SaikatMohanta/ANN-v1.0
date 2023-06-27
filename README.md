#ANN-v1.0
---------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "ANN.h"
---------------------------------------------------------------------------------------------------------------------------------------------------------------
Let's start with an explanation of an artificial neuron and then move on to an artificial neural network.

Artificial Neuron:
An artificial neuron, also known as a perceptron, is a fundamental building block of artificial neural networks. It is inspired by the structure and functionality of biological neurons in the human brain. The purpose of an artificial neuron is to receive input signals, process them, and produce an output signal.

Here's a breakdown of the key components of an artificial neuron:

1. Input: An artificial neuron receives input signals from various sources. Each input is associated with a weight, which determines the importance or significance of that particular input.

2. Weights: Weights are numerical values that are assigned to inputs. They represent the strength or impact of the input on the neuron's output. Higher weights indicate a greater influence on the neuron's decision-making process.

3. Activation Function: After the inputs are multiplied by their respective weights, they are passed through an activation function. The activation function applies a specific mathematical operation to the weighted sum of the inputs and produces an output.

4. Bias: A bias is an additional parameter added to the artificial neuron. It allows the neuron to make adjustments to the output, independent of the input values. The bias helps in controlling the neuron's responsiveness and threshold for activation.

5. Output: The output of the artificial neuron is the result of the activation function. It can be binary (0 or 1) or continuous (any value within a range). The output may also serve as input to other artificial neurons in a neural network.

Artificial Neural Network:
An artificial neural network (ANN) is a collection of interconnected artificial neurons that work together to process information. It is a computational model designed to mimic the behavior of the human brain and perform complex tasks.

Here's an overview of the main components and concepts in an artificial neural network:

1. Input Layer: The input layer is responsible for receiving the initial data or features. Each neuron in the input layer represents a feature or input parameter.

2. Hidden Layers: Hidden layers are intermediate layers between the input and output layers. They process the input data through multiple interconnected neurons. The number of hidden layers and the number of neurons in each layer can vary depending on the complexity of the problem being solved.

3. Weights and Connections: The connections between neurons in different layers have associated weights. These weights determine the influence of one neuron on another. During the training phase, these weights are adjusted to optimize the network's performance.

4. Activation Functions: Each neuron in an artificial neural network applies an activation function to the weighted sum of its inputs. Activation functions introduce non-linearities to the network, enabling it to model complex relationships and make more accurate predictions.

5. Output Layer: The output layer produces the final result or prediction based on the computations performed by the previous layers. The number of neurons in the output layer depends on the nature of the problem. For example, a classification task might have multiple output neurons, each representing a different class label.

6. Training and Learning: Artificial neural networks learn by adjusting the weights and biases during a process called training. Training involves presenting the network with a set of input data with known outputs and iteratively updating the weights to minimize the difference between the predicted outputs and the actual outputs.

By combining multiple artificial neurons in a network with interconnected layers, an artificial neural network can tackle various tasks such as classification, regression, pattern recognition, and more.

I hope this explanation helps clarify the concepts of artificial neurons and artificial neural networks in simple terms!
--------------------------------------------------------------------------------------------------------------------------------------------------------------------- Let's go through the main components and functionality of this library:
______________________________________________________________________

1. Header file "ANN.h":
   - This file includes the necessary libraries and defines the `ANN` class using the `class` keyword.
   - The `ANN` class encapsulates the functionality of the neural network.

2. Constructor:
   - The `ANN` constructor takes parameters such as the number of input nodes, hidden nodes, output nodes, and learning rate.
   - It initializes the member variables and dynamically allocates memory for the arrays used to store weights, biases, and outputs.

3. `initializeWeights()` function:
   - This function is responsible for initializing the weights and biases of the neural network.
   - It uses a loop to assign random values within the range of -1 to 1 to the weight and bias arrays.

4. `sigmoid()` function:
   - This function calculates the sigmoid activation function for a given input value.
   - It uses the mathematical formula 1 / (1 + exp(-x)) to compute the sigmoid output.

5. `forwardPropagation()` function:
   - This function performs the forward propagation step of the neural network.
   - It takes an array of input values and calculates the outputs of the hidden nodes and final outputs using the sigmoid activation function.
   - The calculations involve matrix multiplications between the input values, weights, and biases.

6. `backwardPropagation()` function:
   - This function implements the backward propagation step of the neural network.
   - It takes the input values, target values, and output values as inputs.
   - It calculates the errors and adjusts the weights and biases based on the errors and the learning rate.

7. `train()` function:
   - This function combines the forward propagation and backward propagation steps to train the neural network.
   - It takes the input values and target values as inputs, performs forward and backward propagation, and updates the network's weights and biases.

The provided code offers a basic implementation of an ANN that can be used for training and prediction tasks. However, it's worth noting that this implementation might have limitations or might not be optimized for complex scenarios. Neural network architectures, activation functions, and optimization techniques can vary depending on the specific problem domain and requirements.

To use this ANN library, you would typically include the "ANN.h" header file in your code, create an `ANN` object with the desired parameters, and then use the `train()` and `predict()` methods to train the network and make predictions, respectively.

Keep in mind that if you plan to use this library, you should ensure that you have the necessary libraries and functions available or make the appropriate modifications to fit your specific environment or programming setup.
