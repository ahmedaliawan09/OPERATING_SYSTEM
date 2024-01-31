#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
void *timee(void *arg)
{
time_t tt=time(0);
char* ttt=ctime(&tt);
cout<<"Current Time and Date is: "<<ttt<<endl;
tm *gmt_time=gmtime(&tt);
sleep(8);
return NULL;
}

int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Time;
pthread_create(&Time,NULL,timee,NULL);   //monitorfunc
pthread_join(Time,NULL);
system("pause");
system("wmctrl -c :ACTIVE:");
//pclose(terminal);
return 0;
}
