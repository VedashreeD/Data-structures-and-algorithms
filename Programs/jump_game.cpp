#include<iostream>
#include<vector>

int jump(std::vector<int>& nums) 
{
    for(int i = 1; i < nums.size(); i++)
    {
        //store the max of current index and previous index values
        nums[i] = std::max(nums[i] + i, nums[i-1]);
    }
    //traverse through all the max values indices until we reach the end
    int ind = 0, prev_ind = 0;
    int res = 0;
    while(ind < nums.size() - 1)
    {
	res++;
	prev_ind = ind;
        ind = nums[ind];
	if(ind == prev_ind)
	{
            return -1;
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
    std::cout<<"Enter all the elements : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    int res = jump(nums);
    if(res != -1)
    {
	std::cout<<"The number of jumps required to reach the end : "<<res;
    }
    else
    {
	std::cout<<"Unable to jump to the end!"<<std::endl;
    }
    return 0;
}
