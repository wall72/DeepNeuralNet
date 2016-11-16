#include <iostream>

#define MAX2(a, b) (a) > (b) ? (a) : (b)

using namespace std;

class Neuron {

private:
	double w_; // weight of one input
	double b_; // bias
	double input_, output_; // saved for back-prop

public:
	Neuron() : w_(2.0), b_(1.0) {}
	Neuron(const double& w_input, const double& b_input) : w_(w_input), b_(b_input) {}

	double getActivation(const double& x) {
		// linear or identity activateion functions
		// return x;

		// ReLU activateion function
		return MAX2(0.0, x);
	}

	double getActivationGradient(const double& x) {
		// linear or identity activation functions
		// return 1.0;

		// for ReLU
		return x > 0.0 ? 1.0: 0.0;
	}

	double feedForward(const double& _input) {
		input_ = _input;

		const double sigma = w_ * input_ + b_;

		output_ = getActivation(sigma);

		return output_;
	}

	void propBackward(const double& target) {
		const double alpha = 0.1; // learning rate
		const double grad = (output_ - target) * getActivationGradient(output_);

		w_ -= alpha * grad * input_; // last input_ came from d(wx + b) / dw = x
		b_ -= alpha * grad * 1.0; // last 1.0 came from d(wx + b) db = 1
	}

	void feedForwardPrint(const double& input) {
		cout << "Input = " << input << ", Output = " << feedForward(input) << endl;
	}
};

void main(void) {
	Neuron my_neuron(2.0, 1.0);

	for (int i = 0; i < 100; i++) {
		cout << "Training : " << i << endl;
		my_neuron.feedForwardPrint(1.0);
		my_neuron.propBackward(4.0);
		my_neuron.feedForwardPrint(1.0);
	}
}