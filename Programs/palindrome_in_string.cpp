#include<iostream>
#include<vector>

bool areVectorsEqual(std::vector<int> a, std::vector<int> b)
{
    //check if the vectors are equal
    for(int i=0; i<26; i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

bool checkInclusion(std::string s1, std::string s2) 
{
    //string 2 must be greater than string 1.
    if(s2.size() < s1.size()) 
    {
        return false;
    }
    //add freqs of all chars in string 1.
    std::vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
    std::vector<int> freqS2(26, 0);
    int i = 0, j = 0;
        
    while(i<s2.size())
    {
        //count the frequency in string 2
        freqS2[s2[i]-'a']++; 
         /* if window size == string 1 size, check if we reached all the characters are present and matching, then return true. */
        if(i-j+1==s1.size())
        {
            if(areVectorsEqual(freqS1, freqS2)) return true;
        }
        //if window size is smaller than string 1, continue to check
        if(i-j+1<s1.size()) 
        {
            i++;
        }
        else
        {
            freqS2[s2[j]-'a']--;
            j++;
            i++;
        }
    }
    return false;
}

int main()
{
    std::string s1, s2;
    std::cout<<"Enter the palindrome to be found : "<<std::endl;
    std::cin>>s1;
    std::cout<<"Enter the string : "<<std::endl;
    std::cin>>s2;
    if(checkInclusion(s1, s2))
    {
        std::cout<<"The palindrome : "<<s1<<" is found in the string : "<<s2<<std::endl;

    }
    else{
        std::cout<<"Counldn't find palindrome!"<<std::endl;

    }
    return 0;


}
