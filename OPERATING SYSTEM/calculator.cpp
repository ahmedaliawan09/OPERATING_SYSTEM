#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
int n1,n2,n3=0;
void *cal(void *arg)
{
cout<<endl<<"------------------------------------------------------"<<endl;
int chi;
cout<<"Press 1 to add"<<endl;
cout<<"Press 2 to subtract"<<endl;
cout<<"Press 3 to multiplication"<<endl;
cout<<"Press 4 to division"<<endl;
cout<<"Enter choice: ";
cin>>chi;
cout<<"Enter first number: ";
cin>>n1;
cout<<"Enter second number: ";
cin>>n2;

if(chi==1)
{
n3=n1+n2;
cout<<"Addition of "<<n1<<" and "<<n2<<" = "<<n3<<endl;
}
else if(chi==2)
{
n3=n1-n2;
cout<<"Subtraction of "<<n1<<" and "<<n2<<" = "<<n3<<endl;
}
else if(chi==3)
{
n3=n1*n2;
cout<<"Multiplication of "<<n1<<" and "<<n2<<" = "<<n3<<endl;
}
else if(chi==4)
{
n3=n1/n2;
cout<<"Division of "<<n1<<" and "<<n2<<" = "<<n3<<endl;
}
else
{
cout<<"Invalid input"<<endl;
}
cout<<endl<<"------------------------------------------------------"<<endl;
cout<<"press any key to continue\n";
cin>>chi;


}
int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Cal;
pthread_create(&Cal,NULL,cal,NULL);   //monitorfunc
pthread_join(Cal,NULL);
system("wmctrl -c :ACTIVE:");
//pclose(terminal);
return 0;
}


