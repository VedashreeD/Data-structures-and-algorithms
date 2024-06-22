#include<iostream>
#include<vector>

int numberOfSubstrings(std::string s) 
{
    std::vector<int> chars(3, 0);
    int res = 0, start = 0;
    int n = s.length();
    for(int end = 0; end < n; end++) 
    {
        //increment each char
        chars[s[end] - 'a']++;
        //remove chars from substring start while "abc" are all present in substring
        while (chars[0] && chars[1] && chars[2])
        {
            chars[s[start++] - 'a']--;
        }
        res += start;
    }
    return res;
}

int main()
{
    std::string s;
    std::cout<<"Enter the string : "<<std::endl;
    std::cin>>s;
    std::cout<<"The number of substrings containing \"abc\" characters : "<<numberOfSubstrings(s)<<std::endl;
    return 0; 
}
