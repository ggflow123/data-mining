#reference: https://github.com/jiexunsee/Neural-Network-with-Python
from numpy import exp, array, random, dot,mean,reshape,genfromtxt
import sys

class NeuralNetwork():
    def __init__(self):
        random.seed(1)


        l2 = 30
        l3 = 40

        self.layer1 = 2 * random.random((14, l2)) - 1
        self.layer2 = 2 * random.random((l2, l3)) - 1
        self.layer3 = 2 * random.random((l3, 1)) - 1

    def __sigmoid(self, x):
        return 1/(1+exp(-x))

    def __sigmoid_derivative(self, x):
        return x*(1-x)

    def train(self, train_input, train_output, num):
        for iteration in range(num):
            a2 = self.__sigmoid(dot(train_input, self.layer1))
            a3 = self.__sigmoid(dot(a2, self.layer2))
            output = self.__sigmoid(dot(a3, self.layer3))
            error = train_output - output
            if (iteration % 100 == 99):
                print(1 - mean(error))
            del4 = (train_output - output) * self.__sigmoid_derivative(output)
            del3 = dot(self.layer3, del4.T) * (self.__sigmoid_derivative(a3).T)
            del2 = dot(self.layer2, del3) * (self.__sigmoid_derivative(a2).T)

            adjustment3 = dot(a3.T, del4)
            adjustment2 = dot(a2.T, del3.T)
            adjustment1 = dot(train_input.T, del2.T)

            self.layer1 += adjustment1
            self.layer2 += adjustment2
            self.layer3 += adjustment3

if __name__ == "__main__":
    neural_network = NeuralNetwork()
    train_file = sys.argv[1]
    train_data = genfromtxt(train_file, delimiter=',')
    train_input = train_data[:,:-1]
    train_output_raw = train_data[:,-1]
    train_output_raw2 = reshape(train_output_raw,(1,-1))
    train_output = train_output_raw2.T
    neural_network.train(train_input, train_output, 10000)
