#include "FeedForward.h"

FeedForward::FeedForward(VectorXd &X, TestLayer &L)
{
	this->X = X;
	LL=L;
	Z.resize(LL.getLayerSize());
	A.resize(LL.getLayerSize());
	calculateZ();
	activate();

}

void FeedForward::calculateZ()
{
	Z= (LL.getWeight()*X) + LL.getBias();
}

void FeedForward::activate()
{
	for (int i = 0; i < LL.getLayerSize(); i++)
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
