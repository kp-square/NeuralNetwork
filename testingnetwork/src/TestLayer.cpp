#include "TestLayer.h"

TestLayer::TestLayer(int layer_size,int previous_layer_size,string weight_file,string bias_file)
{
    this->size_layer=layer_size;
    this->size_weight=previous_layer_size;
    this->weight_file=weight_file;
    this->bias_file=bias_file;
    weight.resize(size_layer,size_weight);
    bias.resize(size_layer);

    initializeWeight();

    initializeBias();
    //ctor
}

TestLayer::~TestLayer()
{
    //dtor
}

void TestLayer::initializeWeight()
{
    ifstream wt;
    string file="C:\\Users\\krishna\\CppProjects\\NeuralNet\\"+weight_file;
    wt.open(file.c_str());
    if(!wt)
    {
        cout<<"Error opening the file. Check if file exists in target directory"<<endl;
        exit(0);
    }
    for(int i=0;i<size_layer;i++)
    {
        for(int j=0;j<size_weight;j++)
        {
            wt>>weight(i,j);
        }
    }
    wt.close();
}


void TestLayer::initializeBias()
{

    ifstream bi;
    string file="C:\\Users\\krishna\\CppProjects\\NeuralNet\\"+bias_file;
    bi.open(file.c_str());
    if(!bi)
    {
        cout<<"Error opening the file. Check if file exists in target directory"<<endl;
        exit(0);
    }
    for(int i=0;i<size_layer;i++)
    {
            bi>>bias(i);
    }
    bi.close();
}


MatrixXd TestLayer::getWeight()
{
    return weight;
}

VectorXd TestLayer::getBias()
{
    return bias;
}

int TestLayer::getLayerSize()
{
    return size_layer;
}
