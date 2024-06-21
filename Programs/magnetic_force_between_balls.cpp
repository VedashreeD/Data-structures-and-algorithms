#include<iostream>
#include<vector>
#include<algorithm>

bool ispossible(std::vector<int>& position, int n,int m,int mid)
{
    int ballcount = 1;
    int lastposition = position[0];   
    for(int i = 0; i < n; i++)
    {
        //check if force is more than mid
	//mid is the distance between last ball and current position being considered to place the ball
        if(position[i]-lastposition >= mid)
        {
            ballcount++;
            if(ballcount == m)
            {
                return true;
            }
            //update last position to new position after placing the ball
            lastposition = position[i];
        }
    } 
    //if we can't get forces greater than mid force, and place all the balls
    //with the same or greater force, we try again with low = mid+1 and higher
    //force!
    return false;
}
int maxDistance(std::vector<int>& position, int m) 
{
    std::sort(position.begin(),position.end());
    int start=0;
    int ans=-1;
    int end=position[position.size()-1]-position[0];
       
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if((ispossible(position,position.size(), m, mid)))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n = 0, m = 0;
    std::cout<<"Enter the number of positions to place ball : "<<std::endl;
    std::cin>>n;
    std::vector<int> position(n, 0);
    std::cout<<"Enter all possible positions where the baskets can be placed : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>position[i];
    }
    std::cout<<"Enter the number of balls to be placed :"<<std::endl;
    std::cin>>m;
    std::cout<<"The magnetic force required between any 2 balls : "<<maxDistance(position, m)<<std::endl;
    return 0;
}
