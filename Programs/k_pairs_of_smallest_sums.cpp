#include<iostream>
#include<vector>
#include<queue>
#include<utility>

void kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) 
{
    //use pq to store the sum, and the pairs
    std::priority_queue<std::pair<int,std::pair<int,int>>> pq;
    int n = nums1.size();
    int m = nums2.size();
    //i = nums1.size()
    for(int i = 0; i < n; i++)
    {
        //j = nums2.size()
        for(int j = 0; j < m ; j++)
        {
            //sum of the smallest pairs
            int sum = nums1[i] + nums2[j];
            //if the pq has lesser number of pairs than required, push the sum and nums
            if(pq.size() < k)
            {
                pq.push({sum,{nums1[i],nums2[j]}});
            }
            //if there is a lesser sum than prev sum, pop prev and insert new sum
            else if(sum < pq.top().first)
            {
                pq.pop();
                pq.push({sum,{nums1[i],nums2[j]}});
            }
            //if there are enough pairs of min sum, break from loop
            else
            {
                break; 
            }
        }
    }
    while(!pq.empty())
    {
        //from pq, push the second pairs, first and second elements, and then delete it
        std::cout<<pq.top().second.first<<" "<<pq.top().second.second<<std::endl;
        pq.pop();
    }
}

int main()
{
    int n = 0, m = 0, k = 0;
    std::cout<<"Enter the sizes of array1 and array2 : "<<std::endl;
    std::cin>>n>>m;

    std::vector<int> nums1(n, 0), nums2(m, 0);
    std::cout<<"Enter the first array in ascending order : "<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>nums1[i];
    }
    std::cout<<"Enter the second array in ascending order : "<<std::endl;
    for(int i = 0; i < m; i++)
    {
        std::cin>>nums2[i];
    }
    std::cout<<"Enter the k number of smallest sums to find :"<<std::endl;
    std::cin>>k;

    kSmallestPairs(nums1, nums2, k);
    return 0;

}

