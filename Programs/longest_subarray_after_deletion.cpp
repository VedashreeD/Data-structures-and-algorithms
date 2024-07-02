#include<iostream>
#include<vector>  
    
int longestSubarray(std::vector<int>& nums) 
{
    int i = 0, j = 0, ans = 0, zero_count = 0, count = 0;
    while(i < nums.size())
    {
        //if the curr number is 0, increment zero_count
        if(nums[i] == 0)
            zero_count++;        
        //if more than 1 zero is there, reduce count by 1
        if(zero_count > 1)
        {
            //curr zero is at nums[i], so increment j until previous 0 is not found
            zero_count = 1;
            //increment j until the previous 0 is reached and then increment it
            //again after while loop to 1 num after the previous 0
            while(j <= i && nums[j] == 1)
            {
                j++;
            }
            //increment again to overcome previous 0
            j++;
        }
        //get max length
        ans = std::max(ans,i-j);
        i++;
    }
    return ans;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter all the binary elements : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::cout<<"Size of the longest subarray containing only 1's : "<<longestSubarray(nums)<<std::endl;
    std::cout<<"Note: the longest subarray is calculated by deleting 1 element(0 or 1) within a subarray."<<std::endl;
    return 0;
}
