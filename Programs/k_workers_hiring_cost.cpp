#include<iostream>
#include<vector>
#include<queue>

long long totalCost(std::vector<int>& costs, int k, int candidates) 
{
    int n = costs.size();
    int i = 0;
    int j = n-1;
    long long res = 0;
    int count = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> front_queue, back_queue;
    while(count < k)
    {
	//every loop will contain all the candidates to be checked in one session from front
        while(front_queue.size() < candidates  && i <= j) 
	{
	    front_queue.push(costs[i++]);
	}
	//check from back
        while(back_queue.size() < candidates && j >= i)
	{
            back_queue.push(costs[j--]);
	}
	//if there are candidates in the queue, get the least cost
        int a = front_queue.size() > 0 ? front_queue.top() : INT_MAX; 
        int b = back_queue.size() > 0 ? back_queue.top() : INT_MAX;

	//if cost of front candidate is lesser than right candidate, add it to the res and delete the cost
        if(a <= b)
	{
            res += a;
            front_queue.pop();
        }
        else
	{
            res += b;
            back_queue.pop();
        }
	//increment the sessions completed
        count++;
    }
    return res;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of workers : "<<std::endl;
    std::cin>>n;
    std::vector<int> costs(n, 0);
    for(int i = 0; i < n; i++)
    {
        std::cin>>costs[i];
    }
    int k = 0;
    //run k sessions and hire 1 worker in each session
    std::cout<<"Enter the number of workers required : "<<std::endl;
    std::cin>>k;
    //in each session choose the number of candidates to process
    int candidates = 0;
    std::cout<<"Enter the candidates for each session: "<<std::endl;
    std::cin>>candidates;

    std::cout<<"The total cost of hiring "<<k<<" candidates : "<<totalCost(costs, k, candidates);
    return 0;
}
