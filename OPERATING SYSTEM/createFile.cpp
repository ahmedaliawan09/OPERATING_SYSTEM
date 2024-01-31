#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<fstream>
using namespace std;
void *CF(void *arg)
{
ofstream File;
string filenam; 
cout<<"Enter Filename: ";
cin>>filenam;
filenam=filenam+".txt";
File.open(filenam);
cout<<"File: " << filenam << "is successfully created!!"<<endl;
File.close();
return NULL;
}
