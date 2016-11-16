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

	const int num_const = 3;

	const float y_t[num_const] = { 1.0f, 1.5f, 2.0f };
	const float x[num_const] = { 0.0f, 0.5f, 1.0f };

	const float alpha = 0.01f;

	for (int i = 0; i < 1000; i++) {
		float sqr_error_sum = 0.0f;
		float Ea_sum = 0.0f;
		float Eb_sum = 0.0f;

		for (int i = 0; i < num_const; i++) {
			const float error = y_t[i] - mf.getValue(x[i]);
			const float Ea = error * -x[i];
			const float Eb = error * -1;

			sqr_error_sum += error * error;
			Ea_sum += Ea;
			Eb_sum += Eb;
		}

		cout << "Squared Error = " << 0.5f * sqr_error_sum << endl;

		mf.a_ -= alpha * Ea_sum / (float)num_const;
		mf.b_ -= alpha * Eb_sum / (float)num_const;
	}

	cout << mf.getValue(x[0]) << endl;
	cout << mf.getValue(x[1]) << endl;
	cout << mf.getValue(x[2]) << endl;
}