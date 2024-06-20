#include<iostream>
#include<vector>

int minDays(std::vector<int>& bloomDay, int m, int k) 
{
    int low = 1, high = 1e9;
    int days = -1;
    while(low <= high) 
    {
        //lets store number of days required as mid
        int mid = low + (high - low) / 2;
        int consecutive_flowers = 0, bouquets = 0;
            
        for(int i = 0; i < bloomDay.size(); i++) 
        {
            //if flowers can bloom before required day, increment the count
            if(bloomDay[i] <= mid) 
            {
                consecutive_flowers++;
                //if number of flowers reqches the k required flowers to make a bouquet, 
                //increment number of bouquets ready
                if(consecutive_flowers >= k) 
                {
                    consecutive_flowers = 0;
                    bouquets++;
                }
            } 
            //if flowers have not bloomed before [mid] day, remove length so far
            else 
            {
                consecutive_flowers = 0;
            }
        }
        //if we have enough bouquets, try to make them in lesser number of days
        if(bouquets >= m) 
        {
            days = mid;
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    return days;
}

int main()
{
    int m = 0, k = 0, n = 0;
    std::cout<<"Enter the number of bouquets required : "<<std::endl;
    std::cin>>m;
    std::cout<<"Enter the number of consecutive flowers to make a bouquet : "<<std::endl;
    std::cin>>k;
    std::cout<<"Enter the number of flowers : "<<std::endl;
    std::cin>>n;
    std::vector<int> bloomDay(n, 0);
    std::cout<<"Enter the bloom day of all the flowers : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>bloomDay[i];
    }
    int res = minDays(bloomDay, m, k);
    if(res != -1)
    {
        std::cout<<"The minimum number of days required to make "<<m<<" bouquets with "<<k<< " flowers : "<<res<<std::endl;
    }
    else
    {
        std::cout<<"It is not possible to make the required bouquets with the given flowers"<<std::endl;
    }
    return 0;

}

