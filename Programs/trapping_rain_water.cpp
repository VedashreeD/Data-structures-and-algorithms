#include<iostream>
#include<vector>

int trap(std::vector<int>& elevations) 
{
    int i = 0, j = elevations.size() - 1;
    int left_max = elevations[0], right_max = elevations[j];
    int res = 0;
        
    while(i < j)
    {
        //if the left elevation is smaller than right wall, 
        //add the smaller elevation to result
        if(left_max <= right_max)
        {
            res += (left_max - elevations[i]);
            i++;
            //get the maximum left elevation
            left_max = std::max(left_max, elevations[i]);
        }
        else
        {
            res += (right_max - elevations[j]);
            j--;
            right_max = std::max(right_max, elevations[j]);
        }

    }        
    return res;
}

int main()
{
    int n = 0;
    std::cout<<"Enter the total number of elevations in the map : "<<std::endl;
    std::cin>>n;
    std::cout<<"Enter all the elevations(if ground is flat, enter 0) : "<<std::endl;
    std::vector<int> elevations(n, 0);
    for(int i = 0; i < n; i++)
    {
        int input = 0;
        std::cin>>input;
	elevations.push_back(input);
    }
    std::cout<<"The total amount water trapped between all the elevations is : "<<trap(elevations);
    return 0;
}
