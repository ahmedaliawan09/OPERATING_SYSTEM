#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
void* palindrome(void *arg)
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
int counter=0;
char ctemp;
cout<<"Reverse string is: ";
for(int i=1;i<=sizes;i++)
{
cout<<arr[i];
}
cout<<endl;
for(int i=0;i<sizes;i++)
{
ctemp=s[i];
if(ctemp==arr[i+1])
{
counter++;
}
}
if(sizes==counter)
{
cout<<"Given string "<<s<<" is palindrome"<<endl;
}
else if(sizes!=counter)
{
cout<<"Given string "<<s<<" is not palindrome"<<endl;
}
sleep(8);
return NULL;
}
int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Palindrome;
pthread_create(&Palindrome,NULL,palindrome,NULL);   //monitorfunc
pthread_join(Palindrome,NULL);
//pclose(terminal);
return 0;
}
