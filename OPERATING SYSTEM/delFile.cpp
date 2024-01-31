#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<time.h>
using namespace std;
void *DF(void *arg)
{

//FILE *fp;
char in,fn[35];
cout<<"Enter File Name: ";
cin>>fn;
if(!fopen(fn,"w"))
{
cout<<"Error in opening!"<<endl;
}
else
{
remove(fn);
cout<<"File "<<fn<<" is Successfully deleted"<<endl;
}

return NULL;
}
