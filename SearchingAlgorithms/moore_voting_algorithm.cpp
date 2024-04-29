//Boyer-Moore voting algorithm : Used to determine the majority value in a set of elements. Find a value which appears more frequently than other values. If there is a majority value, it will ultimately emerhe the winner!

#include<iostream>
#include<vector>

std::pair<int, int> boyer_moore_voting_algo(std::vector<int> nums) 
{
    //initialise count to 0 and store the majority element as the first value
    int count = 0;
    int majority_element = 0;
    //start from the 0th element and traverse all elements in o(n) time complexity
    for(auto n : nums)
    {
        //if the count of majority element is 0, replace current majority element with current element
        if(count == 0)
        {
            //replace majority element with current element
            majority_element = n;
        }

	//if the current value is not the majority value, reduce count
        if(n != majority_element)
        {
            count--;
        }
	//increment count if the current value = majority value
        else
        {
            count++;
        }
    }
    return {majority_element, count};
        
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums;
    int input = 0;
    std::cout<<"Enter all the values : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>input;
        nums.push_back(input);
    
    }
    //store majority_element in result.first
    //store count of majority_element in result.second
    std::pair<int, int> result = boyer_moore_voting_algo(nums);
    if(result.second >= (n/2))
    {
        std::cout<<result.first<<" is the majority element"<<std::endl;
    }
    else
    {
        std::cout<<"No element has the majority!"<<std::endl;
    }
    return 0;

}

