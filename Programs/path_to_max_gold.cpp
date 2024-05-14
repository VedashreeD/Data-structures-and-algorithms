#include<iostream>
#include<vector>
#include<functional>

int getMaximumGold(std::vector<std::vector<int>>& grid) 
{
    /*
    each cell contains amount of gold
    return max gold collected
    if(val of cell is 0) don't visit it
    collect gold of current cell and set value to 0 -> walk left/right/up/down
    start and stop collecting gold from any position in the grid
    */
    int m = grid.size();
    int n = grid[0].size();
    int maxGold = 0;
        
    std::function<void(int,int,int)> dfsBacktrack = [&](int i, int j, int currentGold) 
    {
        //out-of-bounds check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) 
        {
            return;
        }
            
        int goldInCurrentCell = grid[i][j];
        currentGold += goldInCurrentCell;
        maxGold = std::max(maxGold, currentGold);
            
        int temp = grid[i][j];
        grid[i][j] = 0;
            
        dfsBacktrack(i + 1, j, currentGold);
        dfsBacktrack(i - 1, j, currentGold);
        dfsBacktrack(i, j + 1, currentGold);
        dfsBacktrack(i, j - 1, currentGold);
            
        grid[i][j] = temp;
    };
        
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (grid[i][j] != 0) 
            {
                dfsBacktrack(i, j, 0);
            }
        }
    }
        
    return maxGold;
}

int main()
{
    int m = 0, n = 0;
    std::cout<<"Enter the row and column size : "<<std::endl;
    std::cin>>m>>n;
    std::vector<std::vector<int>> grid(m, std::vector(n, 0));
    std::cout<<"Enter all the values in the grid : "<<std::endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout<<"Enter value : "<<std::endl;
            std::cin>>grid[i][j];
        }
    }
    std::cout<<"Max gold from the grid : "<<getMaximumGold(grid);
    return 0;


}
