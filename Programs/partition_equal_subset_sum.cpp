#include<iostream>
#include<vector>
#include<numeric>

bool can_partition(std::vector<int>& nums, std::vector<std::vector<int>>& dp, int target_sum, int i , int sum)
{
    //out of bounds check 
    if(i >= nums.size()) 
    {
        return false;
    }
    //if we reach the end of array, check if sum is half of the total sum, return true
    if(i == nums.size() - 1)
    {
        //if the sum is same as target_sum - sum
        if(sum == target_sum / 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    if(dp[i][sum]!=-1) 
    {
        return dp[i][sum];
    }

    //take or not take current number + sum
    //cache the result for future reference 
    return dp[i][sum]=can_partition(nums, dp, target_sum, i+1,sum+nums[i]) || 
    can_partition(nums, dp,target_sum, i+1,sum); 
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter all the elements :"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    int total_sum = accumulate(nums.begin(),nums.end(),0ll);
    if(total_sum & 1)
    {
        std::cout<<"The array cannot be partitioned into equal sum subsets!"<<std::endl;
	return 0;
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(total_sum, -1));
    bool res = can_partition(nums, dp, total_sum, 0,0);
    std::cout<<res;
    if(res)
    {
        std::cout<<"The array can be partitioned into subsets of equal sum!"<<std::endl;
    }
    else
    {
        std::cout<<"The array cannot be partitioned into equal sum subsets!"<<std::endl;
    }


    return 0;
}
