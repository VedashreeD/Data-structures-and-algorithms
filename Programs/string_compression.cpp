#include<iostream>

std::string compressedString(std::string word) 
{
    int count = 0;
    std::string comp = "";
    int i = 0, j = 0;
    while(i < word.size())
    {
        if(word[i] == word[j] && count < 9)
        {
            count++;
            i++;
        }
        else if(count >= 9)
        {
            comp += std::to_string(count) + word[j];
            j = i;
            count = 0;
        }
        //if ith word is different
        else
        {
            comp += std::to_string(count) + word[j];
            count = 0;
            j = i;                
        }
    }
    comp += std::to_string(count) + word[word.size() - 1];
    return comp;
}

int main()
{
    std::string word;
    std::cout<<"Enter the string to be compressed : "<<std::endl;
    std::cin>>word;
    std::cout<<"The compressed string : "<<compressedString(word); 
    return 0;
}
