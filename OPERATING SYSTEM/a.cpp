#include<stdio.h>
#include<iostream>
#include<string.h>
#include<pthread.h>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include <stdlib.h> 
#include <semaphore.h>   
#include <time.h>
using namespace std;
void *agenthread(void *);
void *waterthread(void *);
void *milkthread(void *);
void *coffeethread(void *);

void generaterandomnumber();
int num=0;
class bankaccount
{
  public:
  bankaccount()
  {
      pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
      pthread_cond_t agent= PTHREAD_COND_INITIALIZER;
      pthread_cond_t condmilk= PTHREAD_COND_INITIALIZER;
      pthread_cond_t condcoffee= PTHREAD_COND_INITIALIZER;
      pthread_cond_t condwater= PTHREAD_COND_INITIALIZER;
  }
  void display()
  {   //water milk coffee
  
      sleep(1);
     pthread_mutex_lock(&lock);
     if(num==1)
     { 
       
      sleep(1);
       cout<<"\nwater + milk"<<endl;
       pthread_cond_signal(&condcoffee);
       pthread_mutex_unlock(&lock);
       pthread_mutex_lock(&lock);
       pthread_cond_wait(&agent,&lock);
     }
     if(num==2)
     {
       sleep(1);
       cout<<"\nwater+coffee"<<endl;
       pthread_cond_signal(&condmilk);
       pthread_mutex_unlock(&lock);
       pthread_mutex_lock(&lock);
       pthread_cond_wait(&agent,&lock);
       
     }
     if(num==3)
     {
       sleep(1);
       cout<<"\nmilk+coffee"<<endl;
       pthread_cond_signal(&condwater);
       pthread_mutex_unlock(&lock);
       pthread_mutex_lock(&lock);
       pthread_cond_wait(&agent,&lock);
     }
     else
     {
       pthread_mutex_unlock(&lock);
     }
  }
  void milk()
  { 
      sleep(1);
     pthread_cond_wait(&condmilk,&lock);
     cout<<"\ndeficient will take milk"<<endl;
     pthread_cond_signal(&agent);
  }
  void coffee()
  {
      sleep(1);
     pthread_cond_wait(&condcoffee,&lock);
     cout<<"\ndeficient will take coffee"<<endl;
     pthread_cond_signal(&agent);

  }
  void water()
  {
      sleep(1);
     pthread_cond_wait(&condwater,&lock);
     cout<<"\ndeficient will take water"<<endl;
     pthread_cond_signal(&agent);
  }
  private:
  pthread_mutex_t lock;
  pthread_cond_t agent,condmilk, condwater, condcoffee;
    
}Acc;

void * monitorfunc(void * arg)
{
    cout<<"making three threads of milk water and coffee\n";
    pthread_t agent,milk,water,coffee;
    pthread_create(&agent,NULL,&agenthread,NULL);  
    pthread_create(&milk,NULL,&milkthread,NULL); 
    pthread_create(&coffee,NULL,&coffeethread,NULL); 
    pthread_create(&water,NULL,&waterthread,NULL);
    pthread_join(agent,NULL);
    cout<<"coffee thread joined\n";
    pthread_join(coffee,NULL);
    cout<<"milk thread joined\n";
    pthread_join(milk,NULL);
    cout<<"water thread joined\n";
    pthread_join(water,NULL);
    return 0;
}
void * agenthread(void *)
{ 
   int i=0;
   while(i<3)
   {
      srand (time(NULL));
      num=rand()%3+1;
      cout<<"random generated number is "<<num<<endl;
      Acc.display();
      i++;
   }
return NULL;
}
void * milkthread(void * )
{
    while(1)
    {
        
        Acc.milk();
    }
    return NULL;
}
void * waterthread(void * )
{
    while(1)
    {
        Acc.water();
    }

}
void * coffeethread(void * )
{
    while(1)
    {
        Acc.coffee();
    }
}


