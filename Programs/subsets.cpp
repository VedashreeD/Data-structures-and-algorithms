#include<iostream>
#include<vector>

void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& curr_res, int i)
{
    res.push_back(curr_res);
    for(int idx = i; idx < nums.size(); idx++)
    {
        curr_res.push_back(nums[idx]);
        backtrack(nums, res, curr_res, idx+1);
        curr_res.pop_back();
    }        
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of values : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::vector<std::vector<int>> res;
    std::vector<int> curr_res;
    backtrack(nums, res, curr_res, 0);
    for(auto i : res)
    {
	std::cout<<"[ ";
        for(int j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
    return 0;
}
