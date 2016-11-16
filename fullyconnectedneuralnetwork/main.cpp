#include <iostream>

#include "NeuralNetwork.h"

class Example {
public:
	VectorND<D> x_, y_;
};

void main()
{
	Example xor[4];

	for (int e = 0; e < 4; e++) {
		xor[e].x_.initialize(2);
		xor[e].y_.initialize(1);
	}

	xor[0].x_[0] = 0.0f; xor[0].x_[1] = 0.0f; xor[0].y_[0] = 0.0f;
	xor[1].x_[0] = 0.0f; xor[1].x_[1] = 1.0f; xor[1].y_[0] = 1.0f;
	xor[2].x_[0] = 1.0f; xor[2].x_[1] = 0.0f; xor[2].y_[0] = 1.0f;
	xor[3].x_[0] = 1.0f; xor[3].x_[1] = 1.0f; xor[3].y_[0] = 0.0f;

	VectorND<D> y_temp(1);

	NeuralNetwork nn_;
	nn_.initialize(2, 1, 1);
	nn_.alpha_ = 0.1;

	for (int i = 0; i < 1000; i++)
	{
		for (int e = 0; e < 4; e++) {
			nn_.setInputVector(xor[e].x_);
			nn_.propForward();

			nn_.copyOutputVector(y_temp);
			std::cout << xor[e].y_ << " " << y_temp << std::endl;

			nn_.propBackward(xor[e].y_);
		}

		std::cout << std::endl;
	}
}