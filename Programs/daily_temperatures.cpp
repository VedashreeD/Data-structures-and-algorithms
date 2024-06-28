#include<iostream>
#include<vector>
#include<stack>
std::vector<int> dailyTemperatures(std::vector<int>& temps) 
{
    std::vector<int> results(temps.size());
    std::stack<int> stack;

    for (int i = 0; i < temps.size(); i++) 
    {
        //if the previous temperature is lesser than current temperature 
        while (!stack.empty() && temps[stack.top()] < temps[i]) 
        {
            //store the stck.top day with current day which has higher temperature
            results[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }

    return results;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of days : "<<std::endl;
    std::cin>>n;
    std::cout<<"Enter the temperatures : "<<std::endl;
    std::vector<int> temp(n, 0);
    for(int i = 0; i < n; i++)
    {
        std::cin>>temp[i];
    }
    std::vector<int> res = dailyTemperatures(temp);
    std::cout<<"The number of days to wait until the next higher temperature : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout<<res[i]<<" ";
    }
    return 0;
}
