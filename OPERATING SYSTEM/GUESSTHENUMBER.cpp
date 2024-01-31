#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<string>
#include<cstring> 
#include <ctime>
using namespace std;

char box[10] = {'o','1','2','3','4','5','6','7','8','9'};
void tictac();
int winningcond();
void table();
char choice_char_return(int choice);
void *main_func(void *arg)
{
        int num, guess, tries = 0;
        char x;
	srand(time(0)); //seed random number generator
	num = rand() % 10 + 1; // random number between 1 and 10
	cout << "Guess My Number Game\n\n";

	do
	{
		cout << "Enter a guess between 1 and 10 : ";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "Too high!\n\n";
		else if (guess < num)
			cout << "Too low!\n\n";
		else
			cout << "\nCorrect! You got it in " << tries << " guesses!\n";
	} while (guess != num);
	sleep(8);
	return 0;
}
int main(){
//FILE* terminal=popen("./obj", "r");
pthread_t Guess;
pthread_create(&Guess,NULL,main_func,NULL);   //monitorfunc
pthread_join(Guess,NULL);
system("pause");
return 0;
}

