#include<iostream>
#include<vector>
 
int generateRandomPivot(int low, int high) 
{
    srand(time(NULL));
    return low + rand() % (high - low + 1);
}
 
int partition(std::vector<int>& arr, int low, int high)
{
    int pivotIndex = generateRandomPivot(low, high);
    int pivotValue = arr[pivotIndex];

    std::swap(arr[pivotIndex], arr[high]);
    
    //last element is the pivot element
    int pivot = arr[high];
 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
	    std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return (i + 1);
}
 

void quick_sort(std::vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(std::vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
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
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}

