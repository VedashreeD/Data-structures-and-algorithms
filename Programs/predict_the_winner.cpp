#include<iostream>
#include<vector>

int dfs(int i, int j, std::vector<int>& nums, int turn)
{
    if(i == nums.size() || j == -1)
    {
        return 0;
        //player 1 wins the game
    }
    if(i > j)
    {
        return 0;
        //player 1 wins the game
    }
    //player1 plays first.
    if(turn == 0)
    {
        //find the max of dfs(i++), dfs(j--)
        return std::max(nums[i] + dfs(i+1, j, nums, 1), nums[j] + dfs(i, j-1, nums, 1));
    }
    //player2 plays second.
    else
    {
        //find the min of dfs()
        return std::min(-nums[i] + dfs(i+1, j, nums, 0), -nums[j] + dfs(i, j-1, nums, 0));
    }
}
    
int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements : "<<std::endl;
    std::cin>>n;
    std::vector<int> nums(n, 0);
    std::cout<<"Enter the elements : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums[i];
    }
    if(dfs(0, n-1, nums, 0) >= 0)
    {
        std::cout<<"Player1 wins the array game!"<<std::endl;
    }
    else
    {
        std::cout<<"Player2 wins the array game!"<<std::endl;
    }
    return 0;

}
