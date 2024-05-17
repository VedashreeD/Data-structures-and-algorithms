#include<iostream>
#include<vector>

/*
prices = price of each ith item
needs = number of pieces to buy
special[i][j] = each row = n+1 size; each row has :
[number of ith items in the offer]...[special price]
multiple special offers are there for all items
*/
int solve(std::vector<int>& price, std::vector<std::vector<int>>& special, std::vector<int>& needs, int idx, int n)
{
    //if idx reaches end of special offers, add the original prices for all the 
    //required needs 
    if(idx == special.size())
    {
        int temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp += (needs[i] * price[i]);
        }
        return temp;
    }
    //if the speical offers for any item in curr index exceeds needs, flag and break
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if(special[idx][i] > needs[i]) 
        {
            flag = 1;
            break;
        }
    }

    //if none of the special offers exceed the needs, subtract the needs from the special 
    //offers items
    if(flag == 0)
    {
        for(int i=0; i<n; i++)
        {
            needs[i] -= special[idx][i];
        }
        //Recursively call the solve function with updated needs after
        //subtracting the special offer items (special[idx]). 
        //It adds the special offer price (special[idx][n]) to 
        //the result of the recursive call and stores it in consider
        int consider = special[idx][n] + solve(price, special,needs,idx,n);
        //Restores the original needs by adding back 
        //the quantity of items in the special offer.
        for(int i=0; i<n; i++)
        {
            needs[i] += special[idx][i];
        }
        //If any special offer exceeds the needs, or if the current 
        //special offer is not applicable, it recursively calls 
        //solve with the next special offer
        return std::min(consider, solve(price, special,needs,idx+1,n));
    }
    
    return solve(price, special,needs,idx+1,n);
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of items :"<<std::endl;
    std::cin>>n;
    //price of each item
    std::vector<int> price(n, 0);
    //number of items required
    std::vector<int> needs(n, 0);
    std::cout<<"Enter the prices of all the items : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>price[i];
    }
    std::cout<<"Enter the number of items required : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>needs[i];
    }
    int num_special = 0;
    std::cout<<"Enter the number of special offers : "<<std::endl;
    std::cin>>num_special;
    //special offers contain [number of each item]...[price of all items]. hence n+1
    std::vector<std::vector<int>> special(num_special, std::vector(n+1, 0));
    for(int i = 0; i < num_special; i++)
    {
	std::cout<<"Enter the "<<i+1<<"th offer : "<<std::endl;
        for(int j = 0; j < n+1; j++)
        {
            std::cin>>special[i][j];
        }
    }
    std::cout<<"The lowest possible price : "<<solve(price,special,needs,0,n);
    return 0;
}

