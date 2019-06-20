#include "BackPropagate.h"

BackPropagate::BackPropagate(VectorXd &A2, VectorXd &T)
{
	this->A = A2;
	this->T = T;
	dCost();
}

void BackPropagate::dCost()
{
    dC=A-T;
    dV=dC.cwiseAbs2().sum();
	e= dV/64;
}

VectorXd &BackPropagate::getDC()
{
	return dC;
}

VectorXd &BackPropagate::dActivate(VectorXd &Act)
{
    VectorXd I = VectorXd::Constant(Act.size(),1.0);
	dA = Act.cwiseProduct(I-Act);
	return dA;
}

double BackPropagate::getError()
{
	return e;
}

BackPropagate::~BackPropagate()
{

}
