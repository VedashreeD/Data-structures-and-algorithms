#include<iostream>
#include<vector>

void merge(std::vector<int>& arr, int low, int mid, int high)
{
    int l = mid - low + 1;
    int h = high - mid;
 
    // Create dynamic temp arrays
    int *leftArray = new int[l], *rightArray = new int[h];
 
    // Copy array to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < l; i++)
        leftArray[i] = arr[low + i];
    for (int j = 0; j < h; j++)
        rightArray[j] = arr[mid + 1 + j];
    // Initial index of first sub-array
    int i1 = 0, 
    // Initial index of second sub-array
    i2 = 0,
    // Initial index of merged array
    im = low;
 
    while (i1 < l && i2 < h) 
    {
        if (leftArray[i1] <= rightArray[i2]) 
	{
            arr[im] = leftArray[i1];
            i1++;
        }
        else 
	{
            arr[im] = rightArray[i2];
            i2++;
        }
        im++;
    }
    while (i1 < l) 
    {
        arr[im] = leftArray[i1];
        i1++;
        im++;
    }
    while (i2 < h) 
    {
        arr[im] = rightArray[i2];
        i2++;
        im++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void merge_sort(std::vector<int>& arr, int low, int high)
{
    if (low >= high)
        return; 
 
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}


// Function to print an array
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
    merge_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}
