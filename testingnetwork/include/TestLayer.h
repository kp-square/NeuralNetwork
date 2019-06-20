#ifndef TESTLAYER_H
#define TESTLAYER_H
#include<Eigen/Dense>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
using namespace Eigen;

class TestLayer
{
    public:
        TestLayer(){}
        TestLayer(int layer_size,int previous_layer_size,string,string);
        ~TestLayer();
        void initializeWeight();
        void initializeBias();
        VectorXd getBias();
        MatrixXd getWeight();
        int getLayerSize();

    protected:

    private:
        string weight_file;
        string bias_file;
        int size_layer;
        int size_weight;
        MatrixXd weight;
        VectorXd bias;
};

#endif // TESTLAYER_H
