#include<iostream>
#include<vector>

int minSteps(std::string s, std::string t) 
{
    std::vector<int> count_s(26, 0);
    std::vector<int> count_ts(26, 0);
    int count = 0;
    //increment the count of each character
    for(auto sub : s)
    {
        count_s[sub - 'a']++;
    }
    for(auto sub : t)
    {
        count_ts[sub - 'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        count += abs(count_s[i] - count_ts[i]);
    }
    return count/2;        
}

int main()
{
    std::string s, t;
    std::cout<<"Enter the 2 strings : "<<std::endl;
    std::cin>>s>>t;
    std::cout<<"The minimum number of steps required to make "<<s<<" and "<<t<<" anagrams : "<<minSteps(s, t);
    return 0;
}
