#pragma once
#include "Layer.h"
#include<cmath>
class BackPropagate
{
public:
	BackPropagate(VectorXd &A2, VectorXd &T);
	void dCost();
	VectorXd &dActivate(VectorXd &dA);
	double getError();
	VectorXd &getDC();
	~BackPropagate();
private:
	double e;
	VectorXd dA;
	double dV;
	VectorXd dC;
	VectorXd A;
	VectorXd T;
	VectorXd dW;
};


