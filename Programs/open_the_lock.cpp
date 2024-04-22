#include<iostream>
#include<vector>
#include<set>
#include<queue>

int openTheLock(std::vector<std::string>& deadends, std::string target) 
{
    int operations = 0;
    std::set<std::string> deadend, visited;
    //insert all the deadends into a set for quick access
    for(auto d : deadends) 
    {
        deadend.insert(d);
    }
    //base case : if the starting point is in set of deadends, we can't proceed, so return -1
    if(deadend.count("0000")) return -1;
    //since we have to find the minimum distance from source("0000") to destination("target"), we use bfs algorithm
    std::queue<std::string> q;
    //push the source into queue
    q.push("0000");
    visited.insert("0000");

    while(q.size())
    {
        int sz = q.size();
        while(sz--)
        {
            //get the current lock combinations which have been pushed into the queue
            std::string current_code = q.front();
            q.pop();
            if(current_code == target) 
            {
                //return the number of turns it took to reach the target
                return operations;
            }
            for(int i = 0; i < 4; i++)
            {
                //case 1 : try turning all 4 wheels in clock-wise direction
                std::string new_code = current_code;
                //if ith wheel reached 9, reset to 0, else increment
                new_code[i] == '9' ? new_code[i] = '0' : new_code[i]++;
                //if we have not yet checked the new code and it is not in the list of deadends, push to queue and mark as visited
                if(!visited.count(new_code) and !deadend.count(new_code)) 
                {
                    q.push(new_code);
                    visited.insert(new_code);
                }
                //case 2 : try turning all wheels in anti-clockwise direction
                new_code = current_code;
                new_code[i] == '0' ? new_code[i] = '9' : new_code[i]--;
                if(!visited.count(new_code) and !deadend.count(new_code)) 
                    q.push(new_code), visited.insert(new_code);
            }
        }
        operations++;
    }
    //if non of the operations can provide the required target, return -1
    return -1;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of deadends : ";
    std::cin>>n;
    std::vector<std::string> deadends;
    std::string target;
    std::cout<<"Enter a list of deadends. ex, 0101, 9728 "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::string input;
        std::cin>>input;
        deadends.push_back(input);
    }

    std::cout<<"Enter the target combination : ";
    std::cin>>target;
    int operations = openTheLock(deadends, target);
    if(operations == -1)
    {
        std::cout<<"The lock cannot be opened! Try a different target!";
    }
    else
    {
        std::cout<<"It takes "<<operations<<" turn(s) to open the lock!"<<std::endl;
    }
    return 0;
}
