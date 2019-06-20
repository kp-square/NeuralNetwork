#include"Layer.h"
#include"FeedForward.h"
#include"BackPropagate.h"
#include<fstream>
#include<iostream>
using namespace std;
int num_pixels=784;
int data=1000;
MatrixXd Images(data,num_pixels);
MatrixXd Labels(data,10);

void loadImages()
{
	ifstream infile;
	infile.open("traindata.txt");
	if (!infile)
		cout << "error in file" << endl;

	for (int i = 0; i < data; i++)
	{
	    for(int j=0;j<num_pixels;j++)
            infile >> ::Images(i,j);
	}
}


void loadLabels()
{
    ifstream infile;
	infile.open("trainlabels.txt");
	if (!infile)
		cout << "error in file" << endl;
	int num;
	::Labels=MatrixXd::Zero(data,10);
	for (int i = 0; i < data; i++)
	{
			infile >> num;
			for(int j=0;j<10;j++)
                ::Labels(i,num)=1;
	}
}




int main()
{

    loadImages();

    loadLabels();
    int epochs=30;
    int batch_size=10;
	int iterations= data/batch_size;

	Layer L1(50,num_pixels);

	Layer L2(10,50);
	for(int j=0;j<epochs;j++)
    {
        for (int i = 0; i < iterations; i++)
        {
            RowVectorXd X(num_pixels);
            RowVectorXd T(10);
            double error=0;

            VectorXd dB2=VectorXd::Zero(10);

            MatrixXd dW2=MatrixXd::Zero(10,50);
            VectorXd dB1=VectorXd::Zero(50);
            MatrixXd dW1=MatrixXd::Zero(50,num_pixels);
            for(int k= 0 ; k<batch_size ; k++)
            {

                X=Images.row((i*batch_size)+k);
                T=Labels.row((i*batch_size)+k);

                VectorXd x=X.transpose();
                VectorXd t=T.transpose();

                FeedForward    F1(x, L1);

                VectorXd    A1   =   F1.getActivatedValue();
                FeedForward    F2(A1, L2);
                VectorXd    A2   =   F2.getActivatedValue();
                BackPropagate  B (A2,t);
                MatrixXd       dA2x  =   B.dActivate(A2);
                VectorXd       dB2x  =   B.getDC().cwiseProduct(dA2x);
                MatrixXd       dW2x  =   dB2x * A1.transpose();
                VectorXd       dB1x  =   ((L2.getWeight().transpose())*dB2x).cwiseProduct(B.dActivate(A1));
                MatrixXd       dW1x  =   dB1x * X;
                dB2 += dB2x;

                dW2 += dW2x;
                dB1 += dB1x;
                dW1 += dW1x;
                error += B.getError();
            }

            double         rate = 2.5;
            dB2=dB2/batch_size;
            dW2=dW2/batch_size;
            dB1=dB1/batch_size;
            dW1=dW1/batch_size;

            L2.updateBias  (dB2, rate);
            L2.updateWeight(dW2, rate);

            L1.updateBias  (dB1, rate);
            L1.updateWeight(dW1, rate);

            cout << "error "<<j<<i<<" : "<< error/batch_size << endl;
        }

    }
    L1.saveBias("bias1.txt");
    L1.saveWeights("weight1.txt");
    L2.saveBias("bias2.txt");
    L2.saveWeights("weight2.txt");

}






