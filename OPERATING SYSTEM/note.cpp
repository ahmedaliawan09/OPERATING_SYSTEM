#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<time.h>
using namespace std;
void* notep(void *arg)
//int main()
{
int enter_ch;
cout<<"Press 1 for write in File"<<endl;
cout<<"Press 2 to read File "<<endl;
cout<<"Enter choice: ";
cin>>enter_ch;
if(enter_ch==1)
{
ofstream outFile;
string wr;
cin.ignore();
cout<<"Enter what you want to write below: "<<endl;
getline(cin, wr);
outFile.open("/home/saadashraf/Downloads/finalproject/notepadfile.txt");
outFile<<wr;
outFile.close();
cout<<"This content is saved in notepadfile.txt successfully!"<<endl;
}
else if(enter_ch==2)
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
}
else
{
cout<<"Invalid Input!!"<<endl; 
}
return NULL;
}

int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Notep;
pthread_create(&Notep,NULL,notep,NULL);   //monitorfunc
pthread_join(Notep,NULL);
//pclose(terminal);
return 0;
}
