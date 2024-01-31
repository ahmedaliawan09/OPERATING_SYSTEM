#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<time.h>
using namespace std;
void* showi(void *arg)

{
ifstream inFile;
ofstream outFile;
char filename[50]; 
cout<<"Enter Filename: ";
cin.ignore();
cin.getline(filename,50);
inFile.open(filename);
if(inFile.fail())
{
cout<<"File error,File doesn't Exists"<<endl;
}
else
{
string readng;
cout<<"The content of File is below: "<<endl;
cout<<"_____________________________________________________"<<endl;
while(getline(inFile,readng))
{
cout<<readng<<endl;
}
inFile.close();
}

return NULL;
}
