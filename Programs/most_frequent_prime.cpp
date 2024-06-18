#include<iostream>
#include<vector>
#include<map>
#include<cmath>

class Solution 
{
public:
    std::map<int ,int> prime;
    int ans = 0;
    //checks prime
    bool isPrime(int num) 
    {
        for(int i = 2; i < std::sqrt(num) + 1; i++) 
        {
            if(num % i == 0) 
            {
                return false;
            }
        }
        return true;
    }

    void solve(int i, int j,int n, int m, std::string dir,int num, std::vector<std::vector<int>>& mat)
    {
        //number starts with 0
        //after adding numbers, check for prime, and then check if the frequency
        //of current number is more than currently stored answer.
        //replace/modify accordingly
        if(num>10 && isPrime(num)) 
        {
            prime[num]++;
            if(prime[num] > prime[ans]) 
            {
                ans = num;
            }
            else if(prime[num] == prime[ans])
            {
                ans = std::max(num,ans);
            }
        }
        //out-of-bounds check
        if(i<0 || j<0 || i==n || j==m) 
        {
            return;
        }
        
        if(dir == "NA" || dir == "E") 
        {
            //move east
            solve(i,j+1,n,m,"E",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "SE") 
        {
            //move south-east
            solve(i+1,j+1,n,m,"SE",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "S") 
        {
            //move south
            solve(i+1,j,n,m,"S",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "SW") 
        {
            //move south-west
            solve(i+1,j-1,n,m,"SW",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "W") 
        {
            //move west
            solve(i,j-1,n,m,"W",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "NW") 
        {
            //move north-west
            solve(i-1,j-1,n,m,"NW",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "N") 
        {
            //move north
            solve(i-1,j,n,m,"N",num * 10 + mat[i][j],mat);
        }
        if(dir == "NA" || dir == "NE") 
        {
            //move north-east
            solve(i-1,j+1,n,m,"NE",num * 10 + mat[i][j],mat);
        }
    }

    int mostFrequentPrime(std::vector<std::vector<int>>& mat, int n, int m)
    {
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                solve(i, j, n, m, "NA", 0, mat);
            }
        }
        return ans;
    }
};

int main()
{
    int n = 0, m = 0;
    std::cout<<"Enter the number of rows and cols : "<<std::endl;
    std::cin>>n>>m;
    std::cout<<"Enter all the elements : "<<std::endl;
    std::vector<std::vector<int>> mat(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin>>mat[i][j];
        }
    }
    Solution s;
    if(int res = s.mostFrequentPrime(mat, n, m))
    {
        std::cout<<"The most frequent prime in the given matrix : "<<res<<std::endl;
    }
    else
    {
        std::cout<<"There is no prime number in the given matrix"<<std::endl;
    }
    return 0;

}
