#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
{
    //sort the array in ascending order
    sort(nums.begin(),nums.end());
    std::vector<std::vector<int>> ans;

    int n = nums.size();
    //2 outer nested loops to iterate through unique (i, j), avoiding duplicates
    //by skipping identical elements
    for(int i = 0; i < n; i++)
    {
        //skip duplicates
        if(i > 0 and nums[i] == nums[i - 1])
        {
            continue;
        }
        for(int j = i + 1; j < n; j++)
        {
            //skip duplicates
            if(j > (i + 1) and nums[j] == nums[j - 1])
            {
                continue;
            }
            //2 pointers to navigate through remaining elements, checking for 4sum
            int start = j + 1;
            int end = n - 1;

            while(start < end)
            {
                //calculate sum and adjust pointers accordingly
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[start];
                sum += nums[end];

                if(sum == target)
                {
                    ans.push_back({nums[i] , nums[j] , nums[start] , nums[end]});
                    int low = nums[start];
                    int high = nums[end];
                    start++,end--;
                    //while duplicates are present, increment/decrement pointers
                    while(start < end and nums[start] == low) 
                    {
                        start++;
                    }
                    while(start < end and nums[end] == high) 
                    {
                        end--;
                    }
                }
                else if(sum > target) 
                {
                    end--;
                }
                else 
                {
                    start++;
                }
            }
        }
    }
    //return result
    return ans;
        
}


int main()
{
    int n = 0;
    std::cout<<"Enter the number of values : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    int target = 0;
    std::cout<<"Enter all the numbers : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::cout<<"Enter the target sum : "<<std::endl;
    std::cin>>target;
    std::vector<std::vector<int>> res = fourSum(nums, target);
    for(auto row : res)
    {
        for(auto row_num : row)
        {
            std::cout<<row_num<<" ";
        }
	std::cout<<std::endl;	
    }
    return 0;


}
