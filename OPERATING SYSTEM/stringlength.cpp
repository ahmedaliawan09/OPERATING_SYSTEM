#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std;
void* nofalphabets(void *arg)
{
    char *array_point;
    char c1;
    int count=0, alp=0, digt=0, spcchr=0,oth=0;
    char string_array[100];    
    string str1;
    cout << " Enter a string: ";
    cin>>str1;    
    cout << "Count the letters numbers and other characters:"<<endl;	 cout<<"-------------------------------------------------------------\n";
    cout<<endl;
    strcpy(string_array, str1.c_str());
    for(array_point=string_array;*array_point!='\0';array_point++)
    {
        c1=*array_point;
        count++;
		if (isalpha(c1))
		{
		    alp++;
		}
		else if (isdigit(c1))
		{
		    digt++;
		}
        	else
        	{
            	oth++;;
        	}
    }     
        cout<<" The number of alphabets are: "<<alp<<endl;
        cout<<" The number of digits are: "<<digt<<endl; 
        cout<<" The number of other characters are: "<<oth<<endl<<endl;
        return NULL;
}
