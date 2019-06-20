#include "FeedForward.h"

FeedForward::FeedForward(VectorXd &X, Layer &L)
{

	this->X = X;
	this->L = L;

	Z.resize(L.getLayerSize());
	A.resize(L.getLayerSize());
	calculateZ();
	activate();

}

void FeedForward::calculateZ()
{

    Z = (L.getWeight() * X) + L.getBias();
}

void FeedForward::activate()

{

	for (int i = 0; i < Z.size(); i++)
	{
        A(i) = 1.0 / (1.0 + exp(-Z(i)));
	}

}

VectorXd& FeedForward::getZ()
{
	return Z;
}

VectorXd& FeedForward::getActivatedValue()
{
	return A;
}

FeedForward::~FeedForward()
{

}
