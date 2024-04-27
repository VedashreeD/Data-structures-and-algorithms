#include<iostream>
#include<vector>

int solve(int i, int col, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& dp, int n)
{
    //base case : if all the rows are traversed, exit program
    if(i >= n)
    {
        return 0;
    }
    //if dp of the next col in current index is already filled, return that
    if(dp[i][col+1] != -1)
    {
        return dp[i][col+1];
    }
    int res = 1e9;
    //check if the any current row's columns is equal to previous row's column, don't consider
    for(int j = 0; j < n; j++)
    {
        if(j != col)
        {
            //increment row and store the jth col as adjacent col
            res = std::min(res, grid[i][j] + solve(i+1, j, grid, dp, n));
        }
    }
    return dp[i][col+1] = res;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the grid size : "<<std::endl;
    std::cin>>n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
    std::cout<<"Enter all the grid values : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int input;
            std::cin>>input;
            grid[i][j] = input;
        }
    }
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, -1));
    std::cout<<"The minimum falling sum : "<<solve(0, -1, grid, dp, n);
    return 0;
        
}

