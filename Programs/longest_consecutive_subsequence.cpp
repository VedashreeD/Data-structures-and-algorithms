#include<iostream>
#include<vector>
#include<set>

int longestConsecutive(std::vector<int>& nums) 
{
    std::set<int> st(nums.begin(), nums.end());
    int longest_length = 0;
    for(int num : nums)
    {
        //if there is a previous number in the set, don't count the current number
        //else, if the previous number is not found, calculate the length
        if(st.find(num-1) == st.end())
        {
            int current_num = num;
            int current_length = 1;
            //check for the consecutive sequences
            while(st.find(current_num + 1) != st.end())
            {
                current_num++;
                current_length++;
            }
            longest_length = std::max(longest_length, current_length);
        }
    }
    return longest_length;
}


int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements :"<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter the elements : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    std::cout<<"The number of consecutive subsequences are : "<<longestConsecutive(nums);
    return 0;

}
