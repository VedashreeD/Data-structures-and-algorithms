#include<iostream>
#include<vector>
#include<algorithm>

int numRescueBoats(std::vector<int>& load, int limit) 
{
    std::sort(load.begin() , load.end());
    int left = 0 , boats=0;
    int right = load.size()-1;
    while(left <= right) 
    {
        //if the weight is less than boat capacity, add to boat
        if(load[left] + load[right] <= limit)
        {
            left++;
            right--;
            boats++;
        }
        //reduce the 
        else
        {
            boats++;
            right--;
        }
    }

    return boats;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of people :"<<std::endl;
    std::cin>>n;
    std::vector<int> load;
    std::cout<<"Enter the load(weight of each load) : "<<std::endl;
    int input = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin>>input;
        load.push_back(input);
    }
    int limit = 0;
    std::cout<<"Enter the limit on each boat : "<<std::endl;
    std::cin>>limit;
    int boat_count = numRescueBoats(load, limit);
    std::cout<<"the number of boats required to carry the load : "<<boat_count<<std::endl;
    return 0;
}
