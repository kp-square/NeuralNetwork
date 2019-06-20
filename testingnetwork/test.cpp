#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream file;
    file.open("new.txt");
    if(!file)
    {
        cout<<"cannot open the file";
        return 1;
    }

    while(!EOF)
    {
        string str;
        file >> getline(cin,str);
        cout<<str;
    }


    file.close();
}

