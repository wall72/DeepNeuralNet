#include <iostream>

#define MAX2(a, b) (a) > (b) ? (a) : (b)

using namespace std;

class Neuron {
public:
	double w_; // weight of one input
	double b_; // bias

	double getAct(const double& x) {
		// for linear or identity activateion functions
		return x;

		// for ReLU activateion function
		// return MAX2(0.0, x);
	}

	double feedForward(const double& input) {
		// output y = f(\sigma)
		// \sigma = w_ * input x + b
		// for multiple inputs,
		// \sigma = w0_ * x0_ + w1_ * x1_ + ... + b

		const double sigma = w_ * input + b_;

		return getAct(sigma);
	}
};

void main(void) {
	cout << "Hello World" << endl;

	Neuron my_neuron;
	my_neuron.w_ = 2.0;
	my_neuron.b_ = 1.0;

	cout << "Input = 0.0 " << my_neuron.feedForward(0.0) << endl;
	cout << "Input = 1.0 " << my_neuron.feedForward(1.0) << endl;
	cout << "Input = 2.0 " << my_neuron.feedForward(2.0) << endl;
	cout << "Input = 3.0 " << my_neuron.feedForward(3.0) << endl;
}