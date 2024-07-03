#include<iostream>
#include<vector>
#include<algorithm>

int solve(int i, int j, int k, std::vector<int>& nums)
{
    if(k == 3)
    {
        //return the difference between the smallest and largest value in 3rd move
        return nums[j] - nums[i];
    }
    return std::min(solve(i+1, j, k+1, nums), solve(i, j-1, k+1, nums));
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    if(n < 4)
    {
        std::cout<<"The difference between largest and smallest, after replacing the values in 3 moves will always by 0"<<std::endl;
    }
    else
    {
        std::vector<int> nums(n, 0);
        std::cout<<"Enter all the values : "<<std::endl;
        for(int i = 0; i < n; i++)
        {
            std::cin>>nums[i];
        }
    
        std::sort(nums.begin(), nums.end());
        std::cout<<"The minimum difference between smallest and largest value in 3 moves : "<<solve(0, n-1, 0, nums);
    }
    return 0;

}
