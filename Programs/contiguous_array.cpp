#include<iostream>
#include<vector>
#include<map>

int findMaxLength(std::vector<int>& nums) 
{
    //prefix sums, index is stored in map
    std::map<int,int> mp;
    int max_length = 0;
    int sum = 0;
    //no elements in the map
    mp[0] = -1;

    for(int i = 0; i < nums.size() ; i++)
    {
        //if number is 1, add to sum
        if(nums[i]==1)
        {
            sum+=1;
        }
        //subtract from sum
        else
        {
            sum-=1;
        }
        //check if the current sum is mapped, store the max window size
        if(mp.find(sum)!=mp.end())
        {
            //current index - previous index
            max_length = std::max(max_length, i-mp[sum]);
        }
        //if current sum is not found, add current index to map
        else
        {
            mp[sum] = i;
        }
    }
    return max_length;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter an array containing 0 or 1 : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::cout<<"The maximum contiguous subarray with an equal number of 0 and 1 : "<<findMaxLength(nums); 

    return 0;
}

