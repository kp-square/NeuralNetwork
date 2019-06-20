#pragma once
#include "TestLayer.h"
#include<cmath>
class FeedForward
{
public:
	FeedForward(VectorXd &X, TestLayer &L);
	~FeedForward();
	void activate();
	void calculateZ();
	VectorXd &getActivatedValue();
	VectorXd &getZ();

private:
	TestLayer LL;
	VectorXd X;
	VectorXd Z;
	VectorXd A;
};
