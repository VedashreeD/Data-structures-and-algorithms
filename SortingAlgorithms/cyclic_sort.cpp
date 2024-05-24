#include <iostream>
#include <vector>

void cyclicSort(std::vector<int>& nums) 
{
    int n = nums.size();
    int i = 0;
    while (i < n) 
    {
        //for num : the correct index is num-1
        //if current number is not equal to index, swap with index number
        if (nums[i] != nums[nums[i] - 1]) 
        {
            std::swap(nums[i], nums[nums[i] - 1]);
        } 
        else 
        {
            // If nums[i] is already in its correct position
            i++;
        }
    }
}

int main() 
{
    int n;
    std::cout<<"Enter the number of elements: ";
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        std::cin>>nums[i];
    }
    cyclicSort(nums);

    std::cout<<"Sorted array:"<<std::endl;
    for (int num : nums) 
    {
        std::cout<<num<<" ";
    }

    return 0;
}

