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
	MyFunction mf, mg;

	mf.a_ = (float)rand() / RAND_MAX;
	mf.b_ = (float)rand() / RAND_MAX;

	mg.a_ = (float)rand() / RAND_MAX;
	mg.b_ = (float)rand() / RAND_MAX;

	const float y_t0 = 1.0f;
	const float x_0 = 0.0f;

	const float alpha = 0.01f;

	cout << "Before training y = " << mf.getValue(mg.getValue(x_0)) << endl;

	for (int i = 0; i < 1000; i++) {
		const float error = y_t0 - mf.getValue(mg.getValue(x_0));
		const float sqr_error = 0.5 * error * error;

		cout << "Squared Error = " << sqr_error << endl;

		if (sqr_error < 1e-5) break;

		const float Eaf = -error * mg.getValue(x_0);
		const float Ebf = -error * 1.0f;

		const float Eag = -error * mf.a_ * x_0;
		const float Ebg = -error * mf.a_ * 1.0f;

		mf.a_ -= alpha * Eaf;
		mf.b_ -= alpha * Ebf;

		mg.a_ -= alpha * Eag;
		mg.b_ -= alpha * Ebg;
	}

	cout << "After training y = " << mf.getValue(mg.getValue(x_0)) << endl;
}