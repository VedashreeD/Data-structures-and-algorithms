#include<iostream>
#include<vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) 
{
    int n = nums.size();
    std::vector<int> res(n);
    res[0] = 1;
    //calculate all the elements to the left of i
    for(int i = 1; i < n; i++)
    {
        res[i] = res[i-1] * nums[i-1];
    }
    //calculate all the elements to the right of i
    int right = 1;
    for(int i = n-1; i >= 0; i--)
    {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements :"<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n);
    std::cout<<"Enter all the numbers : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::vector<int> result = productExceptSelf(nums); 
    std::cout<<"The product of array except self : "<<std::endl;
    for(auto res : result)
    {
        std::cout<<res<<" ";
    }
    return 0;
}
