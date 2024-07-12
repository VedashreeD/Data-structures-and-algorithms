#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

int maximumGain(std::string s, int x, int y) 
{
    std::stack<char> st;
    int ans = 0, a1 = 0, b1 = 0;
    //first get the max points possible, by checking max points available
    if (x > y) 
    {
        //for each character in the string, check for ab substring and add points once found
        for (char c : s) 
        {
            if (c == 'b' && !st.empty() && st.top() == 'a') 
            {
                st.pop();
                ans += x;
            } 
            else 
            {
                st.push(c);
            }
        }
    }
    //if x < y 
    else 
    {
        for (char c : s) 
        {
            //check for ba substring and add points
            if (c == 'a' && !st.empty() && st.top() == 'b') 
            {
                st.pop();
                ans += y;
            } 
            else 
            {
                st.push(c);
            }
        }
    }

    //transfer remaining characters back to string
    std::string remaining_str;
    while (!st.empty()) 
    {
        remaining_str.push_back(st.top());
        st.pop();
    }
    std::reverse(remaining_str.begin(), remaining_str.end());

    //Get the remaining points
    for (char c : remaining_str) 
    {
        if (x > y) 
        {
            if (c == 'a' && !st.empty() && st.top() == 'b') 
            {
                st.pop();
                ans += y;
            } 
            else 
            {
                st.push(c);
            }
        } 
        else 
        {
            if (c == 'b' && !st.empty() && st.top() == 'a') 
            {
                st.pop();
                ans += x;
            }
            else 
            {
                st.push(c);
            }
        }
    }

    return ans;
}

int main()
{
    std::string s;
    std::cout<<"Enter the string containing \"ab\" or \"ba\" substrings : "<<std::endl;
    std::cin>>s;
    int x = 0, y = 0;
    std::cout<<"Enter the points to be obtained after removing \"ab\" : "<<std::endl;
    std::cin>>x;
    std::cout<<"Enter the points to be obtained after removing \"ba\" : "<<std::endl;
    std::cin>>y;
    std::cout<<"The max points obtained by removing \"ab\" and \"ba\" from the string : "<<maximumGain(s, x, y)<<std::endl;
    return 0;
}
