#pragma once
#include<iostream>
#include<random>
#include<Eigen/Dense>
#include<fstream>
#include<cmath>
using namespace std;
using namespace Eigen;

class Layer
{
public:
	Layer(){}
	Layer(Layer &l);
	Layer(int layer_size, int previous_layer_size);
	int getLayerSize();
	void initializeWeight();
	void initializeBias();
	MatrixXd getWeight();
	VectorXd getBias();
	void updateWeight(MatrixXd &dW, double rate);
	void updateBias(VectorXd &dB, double rate);
	void saveWeights(string);
	void saveBias(string);


private:
	MatrixXd weight;
	VectorXd bias;
	int layer_size;
	int previous_layer_size;
};

