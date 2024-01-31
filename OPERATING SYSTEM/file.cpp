#include "pthread.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "bits/stdc++.h"
#include "ctime"
#include "cstdlib"
#include<cstdio>
#include<fstream>

using namespace std;
void create()
{
ofstream File;
File.open("student.txt",ios :: out);
File.close();
}
void write()
{
	ofstream File;
	File.open("student.txt",ios ::out|ios::app);
	
	File<<"Hello World\n";
	
	File.close();

}
void del()
{

	char filename[] = "student.txt";
	
	/*	Deletes the file if exists */
	if (remove(filename) != 0)
		perror("File deletion failed");
	else
		cout << "File deleted successfully";
	

}

int main()
{
del();

execl("./finalproject","./finalproject",NULL);
return 0;

}
