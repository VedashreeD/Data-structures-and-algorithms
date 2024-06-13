#include<iostream>
#include<vector>
#include<algorithm>

static bool cmp(std::vector<int>& a, std::vector<int>& b)
{
    return a[0] < b[0];
}
int countDays(int days, std::vector<std::vector<int>>& meetings) 
{
    //sort meetings according to the start day
    std::sort(meetings.begin(), meetings.end(), cmp);
    std::vector<std::vector<int>> merged;
    for (auto meeting : meetings) 
    {
        //if the new merged vector is empty or current meeting starts after previous meeting ends, push new meeting into vector 
        if (merged.empty() || meeting[0] > merged.back()[1]) 
        {
            merged.push_back(meeting);
        } 
        //if new meeting starts before old meeting ends, merge them in-place
        else 
        {
            merged.back()[1] = std::max(merged.back()[1], meeting[1]);
        }
    }
        
    // Calculate total meeting days
    int meeting_days = 0;
    for (auto meeting : merged) 
    {
        meeting_days += meeting[1] - meeting[0] + 1;
    }
        
    // Calculate non-meeting days
    return days - meeting_days;
}

int main()
{
    int days = 0, n = 0;

    std::cout<<"Enter total number of days available to work : "<<std::endl;
    std::cin>>days;
    std::cout<<"Enter the total number of meetings : "<<std::endl;
    std::cin>>n;
    std::cout<<"Enter the meetings in the format : [start_day end_day]"<<std::endl;
    std::vector<std::vector<int>> meetings(n, std::vector<int>(2, 0));
    for(int i = 0; i < n; i++)
    {
        std::cout<<"Enter start and end day of "<<i+1<<" meeting : "<<std::endl;
	std::cin>>meetings[i][0]>>meetings[i][1];
    }
    std::cout<<"Total number of free days(without any meetings) : "<<countDays(days, meetings);
    return 0;
}
