#include <iostream>
#include <vector>

//n : size of the heap, i : index of the root of the subtree to be heapified
void heapify(std::vector<int>& arr, int n, int i) 
{
    //this function follows max-heap property
    int largest = i;
    //get the left and right nodes
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //compare the root with left and right
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    //make sure root is the largest and repeatedly call heapify on
    //the subtrees
    if (largest != i) 
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) 
{
    int n = arr.size();

    // Build max heap 
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) 
    {
        //Move current root to end
        std::swap(arr[0], arr[i]);
        //Call max heap on the reduced heap
        heapify(arr, i, 0); 
    }
}

int main() 
{
    int n = 0;
    std::cout<<"Enter number of elements : "<<std::endl;
    std::cin>>n;

    std::vector<int> arr;
    int input = 0;
    std::cout << "Enter all the values : "<<std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin>>input;
        arr.push_back(input);
    }

    heapSort(arr);

    std::cout<<"Sorted array : "<<std::endl;
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    return 0;
}

