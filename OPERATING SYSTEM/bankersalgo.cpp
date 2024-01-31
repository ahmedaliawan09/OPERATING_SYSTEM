#include<iostream>
using namespace std;
// Number of processes
const int Process = 5;   //p1 p2 p3 p4 p5
                       
// Number of resources  
const int Resources = 3;     //R1 R2 R3 

// Function to find the need of each process
void calculateNeed(int need[Process][Resources], int maxm[Process][Resources], int allot[Process][Resources])
{
    // Calculating Need of each P
    for (int i = 0 ; i < Process ; i++)
        for (int j = 0 ; j < Resources ; j++)

            // Need of instance = maxm instance -  allocated instance
            need[i][j] = maxm[i][j] - allot[i][j];
}
// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][Resources], int allot[][Resources])
{
    int need[Process][Resources];
    // Function to calculate need matrix
    calculateNeed(need, maxm, allot);

    // Mark all processes as unfinish
    bool finish[Process] = {0};

    // To store safe sequence
    int safeSeq[Process];

    // Make a copy of available resources
    int work[Resources];
    for (int i = 0; i < Resources ; i++)
        work[i] = avail[i];

    // While all processes are not finished
    // or system is not in safe state.
    int count = 0;
    while (count < Process)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current
        // work[] resources.
        bool found = false;
        for (int p = 0; p < Process; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of
                // current P need is less
                // than work
                int j;
                for (j = 0; j < Resources; j++)
                    if (need[p][j] > work[j])
                        break;
                // If all needs of p were satisfied.
                if (j == Resources)
                {
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
                    for (int k = 0 ; k < Resources ; k++)
                        work[k] += allot[p][k];
                    // Add this process to safe sequence.
                    safeSeq[count++] = p;
                    // Mark this p as finished
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        // If we could not find a next process in safe
        // sequence.
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    // If system is in safe state then
    // safe sequence will be as below
    cout << "System is in safe state.\nSafe"
         " sequence is: ";
    for (int i = 0; i < Process ; i++)
        cout <<"P"<< safeSeq[i] << " ";
        
    cin>>count;
    system("clear");    
    return true;
}    

// Driver code
void bankersalgoo()
{
    int processes[] = {0, 1, 2, 3, 4};  // there are processes
    // Available instances of resources which is total resources - total allocations
    int avail[] = {3, 3, 2};     // the 
    // Maximum R that can be allocated
    // to processes
    int maxm[][Resources] = {{7, 5, 3},
                             {3, 2, 2},
                             {9, 0, 2},
                             {2, 2, 2},
                             {4, 3, 3}};
    // Resources allocated to processes
    int allot[][Resources] = {{0, 1, 0},
                               {2, 0, 0},
                               {3, 0, 2},
                               {2, 1, 1},
                               {0, 0, 2}};
    // Check system is in safe state or not
    isSafe(processes, avail, maxm, allot);
    
}

