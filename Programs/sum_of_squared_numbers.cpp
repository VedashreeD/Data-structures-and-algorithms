#include<iostream>
#include<cmath>
#include<vector>

std::vector<int> judgeSquareSum(int c) 
{
    long long low = 0, high = sqrt(c);
    std::vector<int> res;
    while(low <= high)
    {
        if((low * low) == c)
        {
            res.push_back(low);
            break;
        }
        else if((high * high) == c)
        {
            res.push_back(high);
            break;
        }
        else if((low * low) + (high * high) == c)
        {
            res.push_back(low);
            res.push_back(high);
            break;
        }
        //if the sum of squares is higher than target, reduce high
        else if((low * low) + (high * high) > c)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return res;
        
}

int main()
{
    int target = 0;
    std::cout<<"Enter the target sum :"<<std::endl;
    std::cin>>target;
    std::vector<int> res = judgeSquareSum(target);
    if(!res.size())
    {
        std::cout<<"No sum of squares can reach the target!"<<std::endl;
    }
    else
    {
        std::cout<<"The square of sums which reach the target : "<<std::endl;
        for(auto r : res)
        {
            std::cout<<r<<" ";
        }
    }
    return 0;
}
