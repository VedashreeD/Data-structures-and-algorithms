#include<iostream>
#include<vector>
#include<stack>

std::vector<int> asteroidCollision(std::vector<int>& asteroids) 
{
    int n = asteroids.size();
    std::stack<int> stk;
        
    for(int i = 0; i < n; i++)
    {
        //if stack is empty or asteroid is positive number,
        if(stk.empty() || asteroids[i] > 0)
        {
            //push the value into stack
            stk.push(asteroids[i]);
        }
        //if asteroid is negative number,
        else
        {
            /*if stack is not empty, and top element is positive(moving in
            opposite direction), if it's value is less than the negative number,
            then pop the element out of the stack.
            */
            while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i]))
            {
                stk.pop();
            }

            /*if stack is not empty, and top of the stack is same size as the 
            negative number, then pop the top element
            */
            if(!stk.empty() && stk.top() == abs(asteroids[i]))
            {
                stk.pop();
            }

            /*if stack is empty, or top element is negative, push the element
            into the stack
            */
            else
            {
                if(stk.empty() || stk.top() < 0)
                {
                    stk.push(asteroids[i]);
                }
            } 
        }
    }
    //create a vector of the stack size and intialise to 0
    std::vector<int> ans(stk.size(), 0);
    int size = stk.size();
    //push the elements into the vector from back to front
    while(!stk.empty())
    {
        ans[--size] = stk.top();
        stk.pop();
    }
    return ans;
        
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of asteroids: "<<std::endl;
    std::cin>>n;
    std::vector<int> asteroids(n, 0);
    std::cout<<"Enter all the asteroids and their directions(+ve:right, -ve:left) :"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>asteroids[i];
    }
    std::vector<int> res = asteroidCollision(asteroids);
    std::cout<<"The asteroids after collision : "<<std::endl;
    for(auto r : res)
    {
        std::cout<<r<<" ";
    } 
    return 0;
}
