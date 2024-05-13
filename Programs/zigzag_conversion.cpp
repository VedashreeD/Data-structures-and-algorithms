#include<iostream>
#include<vector>

std::string convert(std::string s, int numRows) 
{
    //if input row is <= 1, no need for conversion
    if(numRows <= 1)
    { 
        return s;
    }
    int dir = -1;
    int j = 0;
    std::vector<std::string> v(numRows,"");//store the result.
    for(int i = 0;i<s.size();i++)//go through the string
    {
        //if the row is at start/end, inverse the direction
        if(j == numRows-1 || j == 0)
        {
            dir *= (-1);
        }
        //store ith character at jth row in vector
        v[j] += s[i];
        if(dir == 1)
        {
            j++;
        }
        else
        {
            j--;
        }    
    }
    //store the final result back into a string from generated vector
    std::string res;
    for(auto &it:v)
    {
        res += it;
    }
    return res;        
}

int main()
{
    std::string str;
    std::cout<<"Enter the string :"<<std::endl;
    std::cin>>str;
    int n = 0;
    std::cout<<"Enter the number of rows(this is required to perform the zigzag operation using rows) : "<<std::endl;
    std::cin>>n;
    std::cout<<convert(str, n)<<std::endl;
    return 0;
}

