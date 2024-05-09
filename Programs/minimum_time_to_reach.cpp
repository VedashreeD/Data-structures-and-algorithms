#include<iostream>
#include<vector>
#include<cmath>

bool isPossible(std::vector<int>& dist, int speed, double hour)
{
    double time = 0;
    for(int i = 0; i < dist.size(); i++)
    {
        //while this is not the last train to take, use the ceil() to
        //round off the time taken by the train to reach next destination
        time += (i != dist.size()-1)?
                ceil((double)dist[i] / speed) : ((double)dist[i] / speed);
    }
    return time <= hour;
}

int minSpeedOnTime(std::vector<int>& dist, double hour) 
{
/*  hour : time you have to reach office.
    n : number of trains to take sequentially.
    dist : array, where dist[i] is the distance of ith train to travel.
    each train will depart at int hour, so wait is required.
    res = returns the min speed required to reach office on time.
    time = distance/speed. so if speed increases, time will also increase.
    we use binary search to find the min speed required to reach on time.
    */
    int low = 1;
    int high = 1e7; //same as 10000000
    int res = -1;
    while(low <= high)
    {
        //mid gives the min speed of the train required to reach on time.
        int mid = low + (high - low) / 2; //dont use (low +(high - low)) / 2;
        if(isPossible(dist, mid, hour))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of trains : "<<std::endl;
    std::cin>>n;
    std::vector<int> distances(n, 0);
    int input = 0;
    std::cout<<"Enter the distances : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>input;
        distances.push_back(input);
    }
    double hour = 0;
    std::cout<<"Enter the amount of time required to reach : "<<std::endl;
    std::cin>>hour;
    std::cout<<"The minimum time(in hour(s) required to reach destination :"<<minSpeedOnTime(distances, hour);

    return 0;
}

