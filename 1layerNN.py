import numpy as np
import sys
def sigmoid(x,deriv = False):
    if (deriv == True):
        return x*(1-x)
    return 1/(1+np.exp(-x))


def main():
    #process the input
    train_file = sys.argv[1]
    test_file = sys.argv[2]
    train_data = np.genfromtxt(train_file, delimiter=',')
    test_data = np.genfromtxt(test_file, delimiter=',')
    train_input = train_data[:,:-1]
    train_output_raw = train_data[:,-1]
    train_output_raw2 = np.reshape(train_output_raw,(1,-1))
    train_output = train_output_raw2.T
    test_input = test_data[:,:-1]
    test_output = test_data[:,-1]
    seed = int(sys.argv[3])
    np.random.seed(seed)
    #initialize the matrix with random number average to 0
    r_mat = 2*np.random.random((train_input.shape[1],1)) - 1 #result_matrix
    print(train_output_raw2)
    #print(train_output)
    for iter in range(20):

        l0 = train_input
        l1 = sigmoid(np.dot(l0,r_mat))
        l1_error = train_output - l1
        l1_delta = l1_error * sigmoid(l1,True)
        r_mat += np.dot(l0.T,l1_delta)
        print("The accuracy is %.6f in %d iterations" %(1-np.mean(l1_error),iter))
main()
