#include<iostream>
#include<vector>
#include<queue>

int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) 
{
    if(grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1)
    {
        return -1;
    }
    int n = grid.size();
    std::vector<int> dx = {-1, 0, 1};
    std::vector<int> dy = {-1, 0, 1};
    std::queue<std::vector<int>> q;
    q.push({0,0,1});
    grid[0][0] = 1;

    while(!q.empty())
    {
        std::vector<int> cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int steps = cur[2];

        if(x == n-1 && y == n-1)
        {
            return steps;
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int nx = x + dx[i];
                int ny = y + dy[j];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0)
                {
                    q.push({nx, ny, steps+1});
                    grid[nx][ny] = 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the grid size: "<<std::endl;
    std::cin>>n;
    std::vector<std::vector<int>> grid(n, std::vector(n, 0));
    std::cout<<"Enter all the elements(0 - visited cells, 1 - can't visit cell) : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin>>grid[i][j];
        }
    }
    int res = shortestPathBinaryMatrix(grid);
    if(res != -1)
    {
        std::cout<<"The length of the shortest path to the end of the grid : "<<res;
    }
    else
    {
        std::cout<<"There is no clear path to the end of the grid!"<<std::endl;
    }
    return 0;

}
