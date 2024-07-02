#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

std::pair<int, int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) 
{
    std::sort(begin(arr), end(arr));
    //store the fraction, and number1 and number2 pair
    std::priority_queue<std::pair<double, std::pair<int, int>>> maxHeap;
    int n = arr.size();

    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = i + 1; j < n; j++) 
        {
            //push the fraction and the arr[i] and arr[j]
            maxHeap.push({((double) arr[i] / arr[j]), {arr[i], arr[j]}});
            //pop all numbers larger than kth number
            if(maxHeap.size() > k) 
            {
                maxHeap.pop();
            }
        }
    }
    //return i and jth numbers
    auto res = maxHeap.top().second;
    return {res.first, res.second};
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of elements: "<<std::endl;
    std::cin>>n;
    std::vector<int> arr(n, 0);
    std::cout<<"Enter all the numbers : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }
    int k = 0;
    std::cout<<"Enter the kth smallest fraction to retrieve : "<<std::endl;
    std::cin>>k;
    auto [num1, num2] = kthSmallestPrimeFraction(arr, k);
    std::cout<<"The kth smallest fraction is formed with : "<<num1<<" "<<num2<<std::endl;
    return 0;
}
