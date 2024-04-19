//Program to check if people exit the room in the same order they entered it.
//If not, count and print the number of people who exited incorrectly.

#include<iostream>
#include<vector>

int main()
{
    int n = 0;
    std::cout<<"Enter total number of people entering and exiting the room :";
    std::cin>>n;
    std::vector<std::string> enter_order(n, "");
    std::vector<std::string> exit_order(n, "");
    std::cout<<"Enter the order of people entering the room :"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::string input;
        std::cin>>input;
        enter_order.push_back(input);
    }
    std::cout<<"Enter the order of people exiting the room :"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::string input;
        std::cin>>input;
        exit_order.push_back(input);
    }
    int count = 0;
    for(int j = 0; j < exit_order.size(); j++)
    {
        //if both are equal, erase a's first position, and don't count it
        if(enter_order[0] == exit_order[j])
        {
            enter_order.erase(enter_order.begin());
            continue;
        }
        //search for the right position of the person and then erase it, increment count of 
        //wrongly exited people
        for(int i = 0; i < exit_order.size(); i++)
        {
            if(enter_order[i] == exit_order[j])
            {
                count++;
                std::cout<<enter_order[i]<<" "<<"exited wrongly"<<std::endl;
                enter_order.erase(enter_order.begin()+i);
                break;
            }
        }
    }
    std::cout<<"In total, "<<count<<" people exited incorrectly!";
    return 0;
}
