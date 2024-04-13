#include<iostream>
#include<vector>

void insertion_sort(std::vector<int>& arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], 
	 * that are greater than key, to one
	 * position ahead of their current position 
	 */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertion_sort(arr, n);
    print_array(arr, n);

    return 0;
}
