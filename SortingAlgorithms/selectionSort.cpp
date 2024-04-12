#include<iostream>
#include<vector>

void selection_sort(std::vector<int>& arr, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min_element = i;
        for(int j = i+1; j < n ;j++)
        {
            if(arr[j] < arr[min_element])
            {
                min_element = j;
                
            
	    }
	}
        if(min_element != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_element];
            arr[min_element] = temp;
        }
    }
}


void print_array(std::vector<int> arr, int n)
{
    for(int i = 0; i < n; i++)
    {
	    std::cout<<arr[i]<<" ";
    }
}
int main()
{
    int n = 0;
    std::vector<int> arr;
    std::cout<<"Enter the number of elements : ";
    std::cin>>n;
    std::cout<<"Enter all the elements to be sorted : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        int input;
        std::cin>>input;
        arr.push_back(input);
    }
    selection_sort(arr, n);
    print_array(arr, n);

    return 0;
}
