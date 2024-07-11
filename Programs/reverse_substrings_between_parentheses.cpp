#include<iostream>
#include<string>
     
std::string reverseParentheses(std::string& s) 
{
    std::string stk, rev;
    for(char ch: s)
    {
	//Until we reach the closing bracket, keep pushing into the string
        if (ch != ')') 
        {
            stk.push_back(ch);
        }
        else
        {
            rev = "";
            //get the last char before ')'
            char r = stk.back();
            //reverse all chars between ()
            for(; r!='('; r=stk.back())
            {
                rev+=r;
                stk.pop_back();
            }
            //pop out '('
            stk.pop_back();
            //add reversed string back to the string
            stk += rev;
        }
    }
    return stk;
}

int main()
{
    std::string s;
    std::cout<<"Enter a string with matching parentheses, to be reversed : "<<std::endl;
    std::cin>>s;
    std::cout<<"after reversing substrings between each pair of parentheses : "<<reverseParentheses(s);
    return 0;
}

