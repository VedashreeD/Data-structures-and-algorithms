#include<iostream>
#include<vector>
#include<queue>
#include<numeric>

bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) 
{
    std::vector<int> count(n, 0);
    //store the count of left and right children
    for(int i = 0; i < n; ++i)
    {
        if(leftChild[i] != -1)
        {
            count[leftChild[i]]++;
        }
        if(rightChild[i] != -1)
        {
            count[rightChild[i]]++;
        }
    }
    //find the root
    int root = -1;
    for(int i = 0; i < n; i++)
    {
        //from 0 to n-1, if the count of a node is 0, update root
        if(count[i] == 0)
        {
            //update the root to ith node if the root has not been updated even once.
            if(root == -1)
            {
                root = i;
            }
            else
            {
                return false;
            }
        }
    }
    //if the root is still not found, binary tree can't be formed
    if(root == -1)
    {
        return false;
    }
    std::vector<bool> visited(n, false);
    std::queue<int> queue;
    queue.push(root);
    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        if(visited[node])
        {
            return false;
        }
        visited[node] = true;
        if(leftChild[node] != -1)
        {
            queue.push(leftChild[node]);
        }
        if(rightChild[node] != -1)
        {
            queue.push(rightChild[node]);
        }
    }
    //check if sum of visited == n
    return accumulate(visited.begin(), visited.end(), 0) == n;
        
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of nodes in the tree : "<<std::endl;
    std::cin>>n;
    std::vector<int> left(n, -1), right(n, -1);
    std::cout<<"Enter all the left children(-1 if node is not left node)"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>left[i];
    }
    std::cout<<"Enter all the right children(-1 if node is not right node)"<<std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin>>right[i];
    }
    if(validateBinaryTreeNodes(n, left, right))
    {
        std::cout<<"The given nodes form a valid binary tree!"<<std::endl;
    }
    else
    {
        std::cout<<"Not a valid binary tree!"<<std::endl;
    }
    return 0;

}
