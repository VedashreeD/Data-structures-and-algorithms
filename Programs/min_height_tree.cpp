/*to implement the minimum height tree : 
* leaf nodes give the maximum height of the tree. so we remove them, until there are no more than 1 or 2 non-leaf nodes remaining 
* topological sort : we find the indegree for all the nodes. start from leaf nodes and remove them, until we reach last nodes (either 1 or 2 nodes)
*/

#include<iostream>
#include<vector>
#include<queue>

std::vector<int> minHeightTrees(int n, std::vector<std::vector<int>>& edges) 
{
    // Base case with only one node
    if (n == 1) 
    {
	return {0};
    }
    std::vector<int> indegree(n, 0); //to store the number of connections from each node
    std::vector<std::vector<int>> graph(n);
    for (auto& edge : edges) 
    {
        //adjacency list
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        //increment count of connections coming into node
        indegree[edge[0]]++;
        indegree[edge[1]]++;
    }

    std::queue<int> leafQueue;
    for (int i = 0; i < n; i++) 
    {
        //if leaf node, add to queue
        if (indegree[i] == 1) leafQueue.push(i);
    }

    int remainingNodes = n;
    while (remainingNodes > 2) 
    {
        int leafCount = leafQueue.size();
        //reduce the node count after removing the leaf nodes
        remainingNodes -= leafCount;
        for (int i = 0; i < leafCount; i++) 
        {
            //pop the leaf nodes with indegree 1, and reduce the degree of the 
            //leaf nodes' neighbour nodes by 1
            int leaf = leafQueue.front();
            leafQueue.pop();
            for (int neighbor : graph[leaf]) 
            {
                //if after removing the leaf node, the neighbour's 
                //degree reduces to 1, remove the neighbour as well
                if (--indegree[neighbor] == 1) { 
                    leafQueue.push(neighbor);
                }
            }
        }
    }

    std::vector<int> minHeightTrees;
    while (!leafQueue.empty()) 
    {
        //push the remaining nodes into the resultant vector and return
        minHeightTrees.push_back(leafQueue.front());
        leafQueue.pop();
    }
    return minHeightTrees;


}

void print(std::vector<int> res)
{
    std::cout<<"The nodes with which minimum height is possible are :";
    for(auto r : res)
    {
        std::cout<<r;
    }
}

int main()
{
    //example input : 4 nodes : [[0, 1], [1, 2], [3, 1]]
    int n = 0;
    std::cout<<"Enter the total vertices.Note: vertices start from 0 to n-1 : "<<std::endl;
    std::cin>>n;
    std::vector<std::vector<int>> edges;
    std::cout<<"Enter all the edges "<<std::endl;
    for(int i = 0; i < n-1; i++)
    {
	std::cout<<"Enter "<<i<<"th node edges : ";
        int input1, input2;
        std::cin>>input1>>input2;
        edges.push_back({input1, input2});        
    }
    std::vector<int> res = minHeightTrees(n, edges);
    print(res);
    return 0;
}
