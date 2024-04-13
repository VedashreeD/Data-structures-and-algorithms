#include<iostream>
#include<vector>

void bubble_sort(std::vector<int>&a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void print_array(std::vector<int> a, int n)
{
    for(int i = 0; i < n; i++)
    {
	    std::cout<<a[i]<<" ";
    }
}
int main()
{
    int n = 0; 
    int input = 0;
    std::vector<int> arr;
    std::cout<<"Enter the number of elements"<<std::endl;
    std::cin>>n;
    std::cout<<"Enter all the elements to be sorted"<<std::endl;
    for(int i = 0; i < n; i++)
    {
    	std::cin>>input;
	arr.push_back(input);
    }
    bubble_sort(arr,n);
    print_array(arr,n);

    return 0;
}
