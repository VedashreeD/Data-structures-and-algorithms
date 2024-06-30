#include <iostream>
#include <vector>

void findavgTime(const std::vector<int>& processes, int n, const std::vector<int>& burst_time) 
{
    std::vector<int> wt(n, 0), tat(n, 0);

    //Calculate waiting time for the first process
    wt[0] = 0;

    //Calculate the wait time of each process
    for (int i = 1; i < n; i++) 
    {
        wt[i] = wt[i - 1] + burst_time[i - 1];
    }

    //Calculate turn around time for each process
    for (int i = 0; i < n; i++) 
    {
        tat[i] = burst_time[i] + wt[i];
    }

    //Calculate total waiting time and total turn around time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) 
    {
        total_wt += wt[i];
        total_tat += tat[i];
        std::cout << "Process " << processes[i] << " Burst time: " << burst_time[i] << " Wait time: " << wt[i] << " Turn-around time: " << tat[i] << std::endl;
    }

    //Calculate average waiting time and average turn around time
    std::cout << "Average waiting time = " << (float)total_wt / n << std::endl;
    std::cout << "Average turn around time = " << (float)total_tat / n << std::endl;
}

int main() 
{
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<int> processes(n);
    std::cout << "Enter all the process IDs: ";
    for (int i = 0; i < n; i++) 
    {
        std::cin >> processes[i];
    }

    std::vector<int> burst_time(n);
    std::cout << "Enter the burst times of all processes: ";
    for (int i = 0; i < n; i++) 
    {
        std::cin >> burst_time[i];
    }

    findavgTime(processes, n, burst_time);

    return 0;
}

