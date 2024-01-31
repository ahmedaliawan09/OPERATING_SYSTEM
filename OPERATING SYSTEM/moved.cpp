#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<fstream>
using namespace std;
void *moveF(void *arg)
{
string filenamevar;
cin>>filenamevar;
char c;
FILE *fp;
char in,fn[11];
string s=filenamevar;
for(int i=0;i<11;i++)
{
in=s[i];
fn[i]=in;
}
ofstream File;
File.open(filenamevar);
File<<"Hello";
File.close();
ofstream File1;
string var2;
var2="/home/saadashraf/Desktop/"+filenamevar;
File1.open(var2);
ifstream inFile;
inFile.open(filenamevar);
while(inFile.get(c))
{
File1.put(c);
}
sleep(5);
remove(fn);
cout<<"File sample1.txt is successfully moved to Desktop! "<<endl;
return NULL;
}

