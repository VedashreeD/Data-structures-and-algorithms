#include<iostream>
#include<vector>
#include<queue>

int rottingOranges(std::vector<std::vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    std::queue<std::pair<int,int>> rottenQ;
    int totalOranges = 0, currentTotalOranges = 0, days = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //If there is an orange, increment total orange count
            if(grid[i][j] != 0) 
                totalOranges++;
            //if the orange is rotten, push into queue
            if(grid[i][j] == 2) 
                rottenQ.push({i,j});
        }
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    //check the adjacent oranges until there are no more in the queue        
    while(!rottenQ.empty())
    {
        int sz = rottenQ.size();
        currentTotalOranges += sz;
        while(sz--)
        {
            int x = rottenQ.front().first;
            int y = rottenQ.front().second;
            rottenQ.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(ny < 0 || nx < 0 || nx >= n ||ny >= m || grid[nx][ny] == 0 || grid[nx][ny] == 2)
                    continue;
                grid[nx][ny] = 2;
                rottenQ.push({nx,ny});
            }
        }
        if(!rottenQ.empty()) 
            days++;
    }
        
    return currentTotalOranges == totalOranges? days : -1;
        
}


int main()
{
    int n = 0;
    std::cout<<"Enter the grid size :"<<std::endl;
    std::cin>>n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
    std::cout<<"Follow the instructions to enter input : "<<std::endl;
    std::cout<<"0 : no orange, 1:fresh orange, 2:rotten orange"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int input;
            std::cin>>input;
            grid[i].push_back(input);
        }
    }
    int res = rottingOranges(grid);
    if(res == -1)
    {
        std::cout<<"There are still fresh oranges left!"<<std::endl;
    } 
    else{
        std::cout<<"It takes "<<res<<" day(s) for all the oranges to rot!"<<std::endl;
    }
    return 0;
}
