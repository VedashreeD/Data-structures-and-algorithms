#include<iostream>

int countHomogenous(std::string s) 
{
    int left = 0;
    long long res = 0;
    for(int i = 0; i < s.size(); i++)
    {
        //from left till ith index, if we have honogenous substring, add to the result
        if(s[left] == s[i])
        {
            res += i-left+1;
        }
        //add the current char to the result and increment left pointer to ith index
        else
        {
            res += 1;
            left = i;
        }
    }
    return (int)(res % 1000000007);
        
}

int main()
{
    std::string s;
    std::cout<<"Enter the string : "<<std::endl;
    std::cin>>s;
    std::cout<<"The number of homogenous substrings : "<<countHomogenous(s);
    return 0;
}
