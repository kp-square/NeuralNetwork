#include"Layer.h"

Layer::Layer(int layer_size,int previous_layer_size)
{
	this->layer_size = layer_size;
	this->previous_layer_size=previous_layer_size;
	initializeWeight();
	initializeBias();
}

Layer::Layer(Layer &l)
{
	this->weight=l.weight;
	this->bias=l.bias;
	this->layer_size=l.layer_size;
	this->previous_layer_size=l.previous_layer_size;
}

int Layer::getLayerSize()
{
	return layer_size;
}

void Layer::initializeWeight()
{
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<double> d(0.0,1.0);
	weight.resize(layer_size, previous_layer_size);
	for(int i=0;i<layer_size;i++)
        for(int j=0;j<previous_layer_size;j++)
            weight(i,j)=d(gen)/3.0;

}

void Layer::initializeBias()
{
	bias.resize(layer_size);
	random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<double> d(0.0,1.0);
	for(int i=0;i<layer_size;i++)
            bias(i)=d(gen)/3.0;

}

MatrixXd Layer::getWeight()//what is the size of weight returned??
{
	return weight;
}

VectorXd Layer::getBias()//what is the size of bias returned??
{
	return bias;
}

void Layer::updateWeight(MatrixXd &dW, double rate)
{
	weight = weight - (rate*dW);
}

void Layer::updateBias(VectorXd &dB, double rate)
{
	bias = bias - (rate*dB);
}

void Layer::saveWeights(string file )
{
    ofstream outfile;
    outfile.open(file.c_str());
    if(!outfile)
        cout<<"error in creating a file"<<endl;
    outfile<<getWeight();
    outfile.close();

}


void Layer::saveBias(string file)
{
    ofstream outfile;
    outfile.open(file.c_str());
    if(!outfile)
        cout<<"error in creating a file"<<endl;
    outfile<<getBias();
    outfile.close();
}
