#include<iostream>

std::string res;
int isPalindrome(std::string s, int left, int right) 
{
    int count = 0;
    //check if the pointers are within bounds and equal, increment count
    while (left >= 0 && right < s.size() && s[left] == s[right]) 
    {
        --left;
        ++right;
        ++count;
    }

    //if the result size is less than the current palindrome length, then store the 
    //current longest palindrome found, in the result.
    if(res.size() < right-left)
    {
        res = s.substr(left+1, right-left-1);
    }
    return count;
}
int countSubstrings(std::string s) 
{
    int n = s.size(), res = 0;
    for (int i = 0; i < n; i++) 
    {
        //for even and odd length palindromes
        int even = isPalindrome(s, i, i + 1);
        int odd = isPalindrome(s, i, i);
        res += even + odd;
    }
    return res;
}

int main()
{
    std::string s;
    std::cout<<"Enter the string : ";
    std::cin>>s;
    std::cout<<"The number of possible palindromic substrings : "<<countSubstrings(s)<<std::endl;
    std::cout<<"The longest palindromic susbtring within the string : "<<res<<std::endl;

    return 0;
}
