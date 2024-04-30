#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> words) 
{
    std::vector<std::vector<std::string>> res;
    std::map<std::string, std::vector<std::string>> mp;
    for(int i = 0; i < words.size(); i++)
    {
        //consider each word
        std::string s = words[i];
        sort(words[i].begin(), words[i].end());
        //map the original word into the sorted word in map
        mp[words[i]].push_back(s);
    }
    //put the elements of second column of map in res
    for(auto i : mp) 
    {
        res.push_back(i.second);  //push the org strs into 2-d res vector.
    }
    return res;
        
}

int main()
{
    int n;
    std::cout<<"Enter the number of words : "<<std::endl;
    std::cin>>n;
    std::vector<std::string> words;
    std::cout<<"Enter all the words : "<<std::endl;
    std::string input;
    for(int i = 0; i < n; i++)
    {
        std::cin>>input;
        words.push_back(input);
    }
    std::vector<std::vector<std::string>> res = groupAnagrams(words);
    std::cout<<"The anagrams are : "<<std::endl;


    std::cout << "[";
    for(int i = 0; i < res.size(); i++) 
    {
        std::cout << "[";
        for(int j = 0; j < res[i].size(); j++) 
        {
            std::cout<<"\""<<res[i][j]<<"\"";
            if (j < res[i].size() - 1) 
	    {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < res.size() - 1) 
	{
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
    return 0;
}

