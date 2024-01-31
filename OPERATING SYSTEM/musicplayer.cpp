#include <iostream>
#include <cstdlib>
using namespace std;

void *MFP(void *arg)
{
    string filename;
    cout << "Enter the name of the MP3 file: ";
    cin >> filename;
    string command = "mpg321 " + filename;
    system(command.c_str());
    return 0;
}

