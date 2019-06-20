#include"TestLayer.h"
#include"FeedForward.h"
#include<cstdlib>

/*VectorXd loadImage(int indim)
{
    ifstream file;
    file.open("C:\\Users\\krishna\\CppProjects\\NeuralNetworks\\testdata.txt");
    if(!file)
    {
        cout<<"file doesn't exist in the directory";
        exit(1);
    }
    int num_pixels=784;
    int index_image=indim;
    VectorXd X(784);
    for(int i=index_image;i<(index_image+1);i++)
    {
        for(int j=0;j<num_pixels;j++)
            file>>X(i);
    }

    return X;

}
*/


int data=100;
MatrixXd Images(data,784);
RowVectorXd label(data);

void loadImages()
{
	ifstream infile;
	infile.open("C:\\Users\\krishna\\CppProjects\\NeuralNet\\testdata.txt");
	if (!infile)
		cout << "error in file" << endl;

	for (int i = 0; i < data; i++)
	{
	    for(int j=0;j<784;j++)
            infile >> ::Images(i,j);
	}
}


void loadLabels()
{
    ifstream infile;
	infile.open("C:\\Users\\krishna\\CppProjects\\NeuralNet\\testlabels.txt");
	if (!infile)
		cout << "error in file" << endl;
	for (int i = 0; i < data; i++)
	{
			infile >> label(i);

	}
}



int getResult(VectorXd &T)
{
    int result =0;
    double num =T(0);
    for (int i=1;i<10;i++)
    {
        if(num<T(i))
        {
            num=T(i);
            result=i;
        }
    }
    return result;
}


int main()
{
    loadImages();
    loadLabels();
    int correct=0;
    int wrong=0;
    for (int i=0;i<data;i++){
    RowVectorXd    x=Images.row(i);
    VectorXd X=x.transpose();
    TestLayer TL1(50,784,"weight1.txt","bias1.txt");
    TestLayer TL2(10,50,"weight2.txt","bias2.txt");
    FeedForward FF1(X,TL1);
    VectorXd    A1   =   FF1.getActivatedValue();
    FeedForward FF2(A1,TL2);
    VectorXd    A2   =   FF2.getActivatedValue();
    int result=getResult(A2);
    if(result==static_cast<int>(label(i)))
        correct++;
    else
        wrong++;
    }
    cout<<"\n\t\tcorrect : "<<correct<<endl;
    cout<<"\n\t\twrong : "<<wrong<<endl;
    return 0;
}
