#include <iostream>
#include <cstdlib>
using namespace std;

void *VFP(void *arg)
{
    string filename;
    cout << "Enter the filename of the mp4 file to be played: ";
    cin >> filename;
    string command = "mpv " + filename;
    system(command.c_str());
    return 0;
}

