#include<iostream>
#include<vector>

bool dfs(int i, int j, std::vector<std::vector<char>>& board, std::string word, int k)
{
    //base case : variable k keeps count of the words aligning with word
    if(k == word.size())
    {
        return true;
    }
    //if the chars are not equal, it will return false here
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 
    board[i][j] != word[k])
    {
        return false;
    }
    //logic
    char temp = board[i][j];
     //mark as visited, so that it is not again looped
    board[i][j] = ' ';
    //check in adjacent cells. or is used because the full word can
    //be found in atleast 1 direction        
    bool res = dfs(i+1, j, board, word, k+1) || 
            dfs(i, j+1, board, word, k+1) ||
            dfs(i-1, j, board, word, k+1) ||
            dfs(i, j-1, board, word, k+1);
    //after traversing, restore original letter 
    board[i][j] = temp;
    return res;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) 
{
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //once the char is equal to the starting letter, start dfs
            //if the complete word is not found starting at (i, j) position 
            //in the board, go to next index and start over
            if(board[i][j] == word[0] && dfs(i, j, board, word, 0))
            {
                return true;
            }
        }
    }
    return false;
  
 }


int main()
{
    int row = 0, col = 0;
    std::cout<<"Enter the row and col sizes : "<<std::endl;
    std::cin>>row>>col;

    std::vector<std::vector<char>> board(row, std::vector<char>(col));
    char input;
    std::cout<<"Enter all the letters on the board : "<<std::endl;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            std::cin>>input;
            board[i][j] = input;
        }
    }
    std::string word;
    std::cout<<"Enter a word to be searched on the board : "<<std::endl;
    std::cin>>word;

    if(exist(board, word))
    {
        std::cout<<word<<" is found on the board!"<<std::endl;
    } 
    else
    {
        std::cout<<"Could not find "<<word<<" on the board"<<std::endl;
    }
    return 0;
}
