#pragma once
#include "Layer.h"
#include<cmath>
class FeedForward
{
public:
    FeedForward(){}
	FeedForward(VectorXd &X, Layer &L);
	~FeedForward();
	void activate();
	void calculateZ();
	VectorXd &getActivatedValue();
	VectorXd &getZ();

private:
	Layer L;
	VectorXd X;
	VectorXd Z;
	VectorXd A;
};


