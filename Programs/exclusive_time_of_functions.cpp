#include<iostream>
#include<vector>
#include<stack>

std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) 
{
    std::vector<int> ans(n);
    std::stack<std::pair<int,int>> cur;
    int prevTime = 0;
    for (auto s : logs)
    {
        int num = stoi(s.substr(0, s.find(':')));
        int time = stoi(s.substr(s.rfind(':') + 1));
        if (s.find('e') != -1)
        {
            ans[num] += time - prevTime + 1;
            cur.pop();
            prevTime = time + 1;
        }
        else
        {
            if (!cur.empty()) 
                ans[cur.top().first] += time - prevTime ;
            cur.push({num, time});
            prevTime = time;
        }
    }
    return ans;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of tasks : "<<std::endl;
    std::cin>>n;
    int num_logs= 0;
    std::vector<std::string> logs;
    std::cout<<"Enter the number of logs : "<<std::endl;
    std::cin>>num_logs;
    std::string input;
    for(int i = 0; i < num_logs; i++)
    {
	std::cout<<"Enter the log in format [task_number:start/end:run_time] : "<<std::endl;
        std::cin>>input;
        logs.push_back(input);
    }
    std::vector<int> res;
    res = exclusiveTime(n, logs);
    for(int i = 0; i < n; i++)
    {
        std::cout<<"the time to complete "<<i<<" is : "<<res[i]<<std::endl;
    }
    return 0;
}
