#include<iostream>
#include<vector>

void subsets(std::string& path, std::vector<std::string>& res, std::vector<char> input, int n, int k)
{
    //if we reach kth string, return
    if(res.size() == k)
    {
        return;
    }
    //if size of path = n, push into result string vector
    if(path.size() == n)
    {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < 3; i++)
    {
        //if the path size is 0 or path last char is not the current input char
        if(path.size()==0 || path.back()!=input[i])
        {
            path.push_back(input[i]);
            subsets(path, res, input, n, k);
            path.pop_back();
        }
    }
    return;
}
std::string getHappyString(int n, int k) 
{
    /*
    a, b, c chars are used : each string is of length n 
    return kth string in the list
    */
    std::vector<std::string> res;
    std::vector<char> input = {'a', 'b', 'c'};
    std::string path = "";
    subsets(path, res, input, n, k);
    if(res.size() == k)
    {
        return res.back();
    }
    return "";
        
}

int main()
{
    int n, k;
    std::cout<<"This program displays the kth Lexicographical String of All Happy Strings of Length n."<<std::endl;
    std::cout<<"Enter the length of each string :"<<std::endl;
    std::cin>>n;
    std::cout<<"Enter kth string to be returned : "<<std::endl;
    std::cin>>k;
    std::string res =  getHappyString(n, k);
    if(res != "")
    {
        std::cout<<"The kth string is : "<<res<<std::endl;
    }
    else
    {
        std::cout<<"The kth string doesn't exist!"<<std::endl;
    }
    return 0;

}
