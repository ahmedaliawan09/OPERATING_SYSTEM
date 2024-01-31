#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include "a.cpp"
#include "bankersalgo.cpp"
#include "createFile.cpp"
#include "copyfiles.cpp"
#include "delFile.cpp"
#include "moved.cpp"
#include "showinfo.cpp"
#include "stringlength.cpp"
#include "musicplayer.cpp"
#include "videoplayer.cpp"
using namespace std;
int flushramvar;
void threadlist(int ch);
void menulist(int ch);
void rr();
int ram;
int totalram;
int ending;
int rom;
int totalrom;
int usedrom = 20;
char flushtheram;
int mycounter = 0;
int arrivalTime1[15] = { 0, 4, 8, 9, 11, 13, 15, 16, 18, 19, 21, 22, 24, 26, 28 };

int burstTime1[15] = { 6, 7, 9, 6, 4, 5, 6, 3, 5, 4, 6, 4, 3, 4, 6 };

int counter = 0, count_processs = 0, readyqueue[200] = { 0 };

int arr[200];
int process[200];
int arrivalTime[50], burstTime[50], quantumTime = 5;

void flushram()
{
	cout << "do you want to flush the ram\nenter y or n\n";
	cin >> flushtheram;
	if (flushtheram == 'y')
	{
		ram = 0;
	}
else{
ram = flushramvar;
}

	system("clear");
}

void showram()
{
	system("clear");
	cout << "TOTAL RAM:       " << totalram << "GB" << " ( "<<1024*totalram<<" MB )"<< endl;
	cout << "REMAING:         " << ram << "GB" << endl;
	totalrom = rom - usedrom;
	cout << "FREE SPACE(ROM)  " << totalrom << endl;
	cout << "press any key to continue\n";
	cin >> ending;

}

int main()
{
	cout << "enter ram; ";
	cin >> ram;
flushramvar=ram;
	totalram = ram;
	cout << "enter rom; ";
	cin >> rom;
	system("clear");
	cout << "\t\tBISCUIT OPERATING SYSTEM \n";
	sleep(2);
	system("clear");

	while (1)
	{
		int choice, ch;
		bool con = false;
		bool xyz = false;
		jump:
			cout << "\tSHUT DOWN" << endl;
		cout << "Press 1 to shutdown" << endl;
		cout << "\tFILE MANIPULATION" << endl;
		cout << "Press 2 to create file " << endl;
		cout << "Press 3 to copy file " << endl;
		cout << "Press 4 to move file " << endl;
		cout << "Press 5 to delete file " << endl;
		cout << "Press 6 to show file info " << endl;
		cout << "\tOTHER FUNCTIONALITIES" << endl;
		cout << "Press 7 to reverse the string " << endl;
		cout << "Press 8 to check palindrome " << endl;
		cout << "Press 9 to fork() function " << endl;
		cout << "Press 10 for Notepad" << endl;
		cout << "Press 11 to find current time and date" << endl;
		cout << "Press 12 to find See Banker's Algorithm" << endl;
		cout << "Press 13 to find prime of a number." << endl;
		cout << "Press 14 to find number of alphabets in string" << endl;
		cout << "Press 15 for calculator" << endl;
		cout << "\tGAME" << endl;
		cout << "Press 16 for GUESS THE NUMBER " << endl;
		cout << "Press 17 for MONITOR FUNCTION WITH MUTEX &CONDITIONVARIBLE " << endl;
		cout << "MEDIA FUNCTIONALITIES" << endl;
		cout << "Press 18 to play music" << endl;
		cout << "Press 19 to play video" << endl;
		cout << "Press 99 to see ram and rom info " << endl;
		cout << "Enter choice: ";

		cin >> choice;

		if (choice == 1)
		{
			sleep(1);
			cout << "Shutting Down\n";

			return 0;
		}
		else if (choice == 99)
		{
			showram();
			if (ram <= 0)
			{
				flushram();
			}
		}
		else if (choice > 20 || choice < 1)
		{
			cout << "Invalid Input" << endl;
		}
		else
		{
			readyqueue[count_processs] = choice;	///adding process in ready queue
			count_processs++;
		}

		if (ram > 0)
		{
			cout << "      Process arrives     " << endl;
			int tyt = 0;
			for (int i = 0; i < count_processs; i++)	//////////printing names of process in ready queue
			{
				cout << "P" << readyqueue[i] << " Named ";
				menulist(readyqueue[i]);
				cout << endl;
			}

			cout << "___________" << endl;
			cout << endl;
			cout << "\t \t Round Robin " << endl;
			rr();

			cout << "Process " << choice << " Turn" << endl;

			if (choice == 1) {}
			else if (choice == 2)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 0.1;
					pthread_t mkf;
					pthread_create(&mkf, NULL, CF, NULL);
					pthread_join(mkf, NULL);
				}
			}
			else if (choice == 3)
			{
				ram = ram - 0.1;
				pthread_t cp;
				pthread_create(&cp, NULL, copyF, NULL);
				pthread_join(cp, NULL);
			}
			else if (choice == 4)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					pthread_t mvf;
					pthread_create(&mvf, NULL, moveF, NULL);
					pthread_join(mvf, NULL);
				}
			}
			else if (choice == 5)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					pthread_t de;
					pthread_create(&de, NULL, DF, NULL);
					pthread_join(de, NULL);
				}
			}
			else if (choice == 6)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					pthread_t shi;
					pthread_create(&shi, NULL, showi, NULL);
					pthread_join(shi, NULL);
				}
			}
			else if (choice == 7)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./reverseobj");
					goto jump;
				}
			}
			else if (choice == 8)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./palindromeobj");
					goto jump;
				}
			}
			else if (choice == 9)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./forkobj");
					goto jump;
				}
			}
			else if (choice == 10)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./noteobj");
					goto jump;
				}
			}
			else if (choice == 11)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./timeobj");
					goto jump;
				}
			}
			else if (choice == 12)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					bankersalgoo();
				}
			}
			else if (choice == 13)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./primeobj");
					goto jump;
				}
			}
			else if (choice == 14)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					pthread_t al;
					pthread_create(&al, NULL, nofalphabets, NULL);
					pthread_join(al, NULL);
				}
			}
			else if (choice == 15)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./calculatorobj");
					goto jump;
				}
			}
			else if (choice == 16)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					system("gnome-terminal --disable-factory -- ./guessobj");
					goto jump;
				}
			}
			else if (choice == 17)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
					ram = ram - 1;
					pthread_t mon;
					pthread_create(&mon, NULL, monitorfunc, NULL);	//monitorfunc
					pthread_join(mon, NULL);
				}
			}
			else if (choice == 18)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
                                        ram = ram-1;
					pthread_t mfp;
					pthread_create(&mfp, NULL, MFP, NULL);	//monitorfunc
					pthread_join(mfp, NULL);
				}
			}
			else if (choice == 19)
			{
				if (ram <= 0)
				{
					cout << "ram is full" << endl;
					flushram();
				}
				else
				{
                                        ram = ram-1;
					pthread_t vfp;
					pthread_create(&vfp, NULL, VFP, NULL);	//monitorfunc
					pthread_join(vfp, NULL);
				}
			}

			cout << endl;
		}
	}

	return 0;
}

void rr()
{
	int asp;
	if (ram > 0)
	{
		for (int x = 0; x < count_processs; x++)
		{
			cout << endl;
			asp = readyqueue[x];
			cout << "Process " << x + 1 << endl;
			menulist(asp);
			cout << endl;
			arrivalTime[x] = arrivalTime1[x];
			cout << "Arrival Time=" << arrivalTime[x] << endl;
			burstTime[x] = burstTime1[x];
			cout << "Burst Time=" << burstTime[x] << endl;
		}

		cout << endl;
		cout << "_________________" << endl;
		cout << "Time Quantum= " << quantumTime << endl;
	}
}

void menulist(int ch)	////Name of each process
{
	if (ch == 2)
	{
		cout << "Create File ";
	}
	else if (ch == 3)
	{
		cout << "Copy File ";
	}
	else if (ch == 4)
	{
		cout << "Move File ";
	}
	else if (ch == 5)
	{
		cout << "Delete File ";
	}
	else if (ch == 6)
	{
		cout << "Show File-info ";
	}
	else if (ch == 7)
	{
		cout << "Reverse String ";
	}
	else if (ch == 8)
	{
		cout << "Palindrome ";
	}
	else if (ch == 9)
	{
		cout << "FORK FUNCTION ";
	}
	else if (ch == 10)
	{
		cout << "Notepad ";
	}
	else if (ch == 11)
	{
		cout << "Current Time ";
	}
	else if (ch == 12)
	{
		cout << "BANKER'S ALGORITHM ";
	}
	else if (ch == 13)
	{
		cout << "Prime Number ";
	}
	else if (ch == 14)
	{
		cout << "No-of-alphabets ";
	}
	else if (ch == 15)
	{
		cout << "Calculator ";
	}
	else if (ch == 16)
	{
		cout << "GUESS THE NUMBER";
	}
	else if (ch == 17)
	{
		cout << "MONITORS";
	}
	else if (ch == 18)
	{
		cout << "MusicPlayer" << endl;
	}
	else if (ch == 19)
	{
		cout << "VideoPlayer" << endl;
	}
}
