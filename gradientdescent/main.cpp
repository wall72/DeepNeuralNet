#include <iostream>

using namespace std;

class MyFunction { // linear hypothesis
public:
	float a_, b_;

	MyFunction() : a_(0.0f), b_(0.0f) {}

	float getValue(const float& x) {
		return a_ * x + b_;
	}
};

void main(void) {
	MyFunction mf;

	const float y_t0 = 1.0f;
	const float x_0 = 0.0f;

	const float alpha = 0.01f;

	for (int i = 0; i < 1000; i++) {
		const float error = y_t0 - mf.getValue(x_0);

		cout << "Squared Error = " << 0.5 * error * error << endl;

		const float Ea = error * -x_0;
		const float Eb = error * -1;

		mf.a_ -= alpha * Ea;
		mf.b_ -= alpha * Eb;
	}

	cout << mf.getValue(x_0) << endl;
}