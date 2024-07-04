#include<iostream>

int equalSubstring(std::string s, std::string t, int maxCost) 
{
    int cost = 0, maxLength = 0, j = 0;
    for(int i = 0; i < s.size(); i++)
    {
        cost += abs(s[i] - t[i]);
        //if the diff between the 2 strings are less than maxCost, get the max window size
        if(cost <= maxCost)
        {
            maxLength = std::max(maxLength, i-j+1);
        }
        while(cost > maxCost)
        {
            cost -= abs(s[j] - t[j]);
            j++;

        }
    }
    return maxLength;
}

int main()
{
    std::string s, t;
    int maxCost = 0;
    std::cout<<"Enter the string s : "<<std::endl;
    std::cin>>s;
    std::cout<<"Enter the string t : "<<std::endl;
    std::cin>>t;
    std::cout<<"Enter the max cost : "<<std::endl;
    std::cin>>maxCost;
    std::cout<<"The max length of s which can be changed to be the same as the substring t, with a lesser cost than max cost : "<<equalSubstring(s, t, maxCost);
    return 0;
}
