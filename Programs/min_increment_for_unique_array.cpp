#include<iostream>
#include<vector>
#include<algorithm>

int minIncrementForUnique(std::vector<int>& nums) 
{
    std::sort(nums.begin(), nums.end());
    int res = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        //once we increment 2 adjacent numbers, there is a chance of 
        //next number begin smaller than current number. so we need to increment
        //next number as well
        if(nums[i] <= nums[i-1])
        {
            //so we get the diff between current and previous number
            //and store current number as previous number+1
            res += nums[i-1] - nums[i]+1;
            nums[i] = nums[i-1] + 1;
        }

    }
    return res;  
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter the elements : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::cout<<"Number of moves required to make the array unique : "<<minIncrementForUnique(nums);
    return 0; 

}

