#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
void* reverse(void *arg)
{
string s,rev;
cout<<"Enter String: ";
cin>>s;
char in;
int sizes=s.size();
int temp=sizes;
char *arr=new char[sizes];
for(int i=0;i<sizes;i++)
{
in=s[i];
arr[temp]=in;
temp--;
}
cout<<"Reverse string is: ";
for(int i=1;i<=sizes;i++)
{
cout<<arr[i];
}
cout<<endl;
sleep(8);
 return NULL;
}
int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Reverse;
pthread_create(&Reverse,NULL,reverse,NULL);   //monitorfunc
pthread_join(Reverse,NULL);
system("pause");
return 0;
}


