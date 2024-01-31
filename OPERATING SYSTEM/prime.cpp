#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
void* findprime(void *arg)
{
    int i, n;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> n;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";
cin>>n;
sleep(8);
return NULL;
}
int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Prime;
pthread_create(&Prime,NULL,findprime,NULL);   //monitorfunc
pthread_join(Prime,NULL);
system("pause");
return 0;
}
