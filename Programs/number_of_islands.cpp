#include<iostream>
#include<vector>

class Islands 
{
public:
    bool isValid(int i, int j, int n, int m, std::vector<std::vector<char>>& grid)
    {
        if(i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '1')
            return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, std::vector<std::vector<char>>& grid)
    {
        grid[i][j] = '0';
        if(isValid(i-1, j, n, m, grid))
            dfs(i-1, j, n, m, grid);
        if(isValid(i+1, j, n, m, grid))
            dfs(i+1, j, n, m, grid);
        if(isValid(i, j-1, n, m, grid))
            dfs(i, j-1, n, m, grid);
        if(isValid(i, j+1, n, m, grid))
            dfs(i, j+1, n, m, grid);
    }
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return res;
    }
};

int main()
{
    int n = 0, m = 0;
    std::cout<<"Enter the number of rows and columns in the island grid : "<<std::endl;
    std::cin>>n>>m;

    std::vector<std::vector<char>> grid(n, std::vector<char>(m, '0'));
    std::cout<<"Enter the binary grid : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin>>grid[i][j];
        }
    }
    Islands ild;
    std::cout<<"The number of islands : "<<ild.numIslands(grid);
    return 0;
}
