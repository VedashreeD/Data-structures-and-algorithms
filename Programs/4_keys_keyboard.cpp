#include<iostream>
#include<vector>
int maxA(int n) 
{
    std::vector<int> dp(n+3, 0);
    for(int i = 1; i <= n; i++) 
    {
        dp[i] = i;
       for(int j = 1; j < i - 2; j++) 
       {
            dp[i] = std::max(dp[i], dp[j]*(i-j-1));
        }
    }
    return dp[n];
}

int main()
{
    int n = 0;
    std::cout<<"Enter the max number of keyboard presses:"<<std::endl;
    std::cin>>n;
    std::cout<<"Using A, ctrl-a, ctrl-c and ctrl-v, the max number of A's to print on screen is :"<<maxA(n)<<std::endl;
    return 0;
}
