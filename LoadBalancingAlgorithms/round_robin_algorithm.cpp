#include <iostream>
#include <vector>

//Function to calculate average waiting time and turn around time using Round Robin scheduling
void findavgTime(const std::vector<int>& processes, int n, const std::vector<int>& burst_time, int quantum) 
{
    //Initialize vectors for waiting time, turn around time, and remaining burst time
    std::vector<int> wt(n, 0);
    std::vector<int> tat(n, 0); 
    std::vector<int> rem_bt(burst_time.begin(), burst_time.end());

    //Current time
    int t = 0; 
    int total_wt = 0; 
    int total_tat = 0;
    bool done = false;

    //Wait-time : time spent by a process in the ready queue
    while (!done)
    {
        done = true; //Assume all processes are done
        //Check if all processes have executed
        for (int i = 0; i < n; i++) 
        {
            if (rem_bt[i] > 0) //If process i still has remaining burst time
            { 
                done = false; //Set flag to false as there are pending processes
                //If remaining burst time is more than quantum, execute for quantum time and move out
                if (rem_bt[i] > quantum) 
                {
                    //Execute for quantum time and add remaining required time to rem_bt of ith process
                    t += quantum;
                    rem_bt[i] -= quantum; //Reduce remaining burst time by quantum
                } 
                else 
                { //If remaining burst time is less than or equal to quantum
                    t += rem_bt[i]; 
                    wt[i] = t - burst_time[i]; //Current time after process finishes execution - how long the process required CPU execution is wait time
                    rem_bt[i] = 0;
                }
            }
        }
    }

    //turn-around time :  time taken by process from its arrival in the ready queue until its completion
    //it including both waiting time(ready queue) + execution time(CPU execution)
    for (int i = 0; i < n; i++) 
    {
        tat[i] = burst_time[i] + wt[i]; //Turn around time is burst time + waiting time
        total_wt += wt[i]; //Sum of all waiting times
        total_tat += tat[i]; //Sum of all turn around times

        std::cout<<"Process "<<(i + 1)<<" Burst time : "<<burst_time[i]<<" Wait time : "<<wt[i]<<" Turn-around time : "<<tat[i]<<std::endl;
    }

    //Average waiting time and turn around time of all processes
    std::cout << "Average waiting time = " << (float)total_wt / n << std::endl;
    std::cout << "Average turn around time = " << (float)total_tat / n << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<int> processes(n);
    std::cout << "Enter all the process IDs: ";
    for (int i = 0; i < n; i++) 
    {
        std::cin >> processes[i];
    }

    //Time required by each process for CPU execution
    std::vector<int> burst_time(n);
    std::cout << "Enter the burst times of all processes: ";
    for (int i = 0; i < n; i++) 
    {
        std::cin >> burst_time[i];
    }

    //Fixed time slice allocated to each process for CPU execution
    int quantum;
    std::cout << "Enter the time quantum: ";
    std::cin >> quantum;

    findavgTime(processes, n, burst_time, quantum);

    return 0;
}
