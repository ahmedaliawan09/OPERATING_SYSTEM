#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<fstream>
using namespace std;
void *copyF(void *arg)
{
char c;
ofstream File;
File.open("sample.txt");
File<<"Happy New Year";
File.close();
ifstream i_file("sample.txt");
ofstream o_file("copied.txt");
while(i_file.get(c))
{
o_file.put(c);
}
i_file.close();
o_file.close();
cout<<"File sample.txt is sucessfully copied with name copied.txt !!"<<endl;
return NULL;
}
