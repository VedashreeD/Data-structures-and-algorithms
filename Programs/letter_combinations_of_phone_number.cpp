#include<iostream>
#include<vector>

    void solve(std::string &digits, std::vector<std::string> &choice, std::vector<std::string> &result, std::string &ans, int index)
    {
        //each string should be the size of digits
        if(ans.length() == digits.size())
        {
            result.push_back(ans);
            return;
        }

        //store the ith digit in variable and get the corresponding string.
        //digits[index] - '0' gives individual digits
        //choice[idx-2] gives the string. ex, for digit = 2, string = abc
        int idx = digits[index] - '0';
        std::string temp = choice[idx-2];

        /*push individual alphabet into the result and then delete the answer
        */
        for(int i=0;i<temp.length();i++)
        {    
            ans.push_back(temp[i]);
            solve(digits, choice, result, ans, index+1);
            ans.pop_back();
        }

    }

    std::vector<std::string> letterCombinations(std::string digits) 
    {
        //if there are no digits, return empty string vector
        if(digits.size() == 0)
            return {};

        std::vector<std::string> choice = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        std::vector<std::string> result;
        std::string ans = "";

        solve(digits, choice, result, ans, 0);

        return result;
    }

int main()
{
    std::string digits;
    std::cout<<"Enter the digits : "<<std::endl;
    std::cin>>digits;
    try 
    {
        if (digits.empty()) 
	{
            throw std::invalid_argument("Input string is empty");
        }

        for (char digit : digits) 
	{
            if (digit < '2' || digit > '9') 
	    {
                throw std::invalid_argument("Input string contains out-of-range characters");
            }
        }

        std::vector<std::string> res = letterCombinations(digits);
        std::cout << "All the letter combinations of the given digit are : " << std::endl;
        for(auto combination : res)
        {
            std::cout << combination << " ";
        }
        std::cout << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;

}
