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
		int c = rand() % num_const;

		const float error = y_t[c] - mf.getValue(x[c]);

		cout << "Squared Error = " << 0.5f * error * error << endl;

		const float Ea = error * -x[c];
		const float Eb = error * -1;

		mf.a_ -= alpha * Ea;
		mf.b_ -= alpha * Eb;
	}

	cout << mf.getValue(x[0]) << endl;
	cout << mf.getValue(x[1]) << endl;
	cout << mf.getValue(x[2]) << endl;
}