#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;

void* forkfunction(void *arg)
{

int pid,pid2,pid3,d1,d2;
int arr[100],fd[2];
pipe(fd);
pid=fork();
if (pid ==0)
sleep(3);
else {
cout<<"Enter 2 digits \n";
cin>>d1>>d2;
arr[0]=d1;arr[1]=d2;
write(fd[1],arr,100);
pid2=fork();
sleep(2);
if(pid2==0)
{
read(fd[0],arr,100);
cout<<"add -> "<<arr[0]+arr[1]<<endl;
cout<<"sub -> "<<arr[1]+arr[1]<<endl;
}
cout<<"Enter 2 digits \n";
cin>>d1>>d2;
arr[0]=d1;arr[1]=d2;
write(fd[1],arr,100);
pid3=fork();
if(pid3==0)
{
read(fd[0],arr,100);
cout<<"Mul -> "<<arr[0]*arr[1]<<endl;
cout<<"Div -> "<<arr[0]/arr[1]<<endl;
}
else sleep(1);
system("clear");
}
sleep(8);


return 0;
}
int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Fork;
pthread_create(&Fork,NULL,forkfunction,NULL);   //monitorfunc
pthread_join(Fork,NULL);
//pclose(terminal);
return 0;
}
