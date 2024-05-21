#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfs(std::vector<std::vector<int>>& graph, int start) 
{
    //keep track the vertices visited
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    //
    std::vector<int> result;

    visited[start] = true;
    //push the starting vertex into the queue
    q.push(start);

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        //push 
        result.push_back(current);
        //traverse through all the neighbours of current vertex
        for (int neighbor : graph[current]) 
        {
            if (!visited[neighbor]) 
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() 
{
    int vertices, edges;
    std::cout<<"Enter the number of vertices and edges: ";
    std::cin>>vertices>>edges;

    std::vector<std::vector<int>> graph(vertices);

    std::cout << "Enter the edges. Ex : 1 2 connects 1st vertex to 2nd vertex :" << std::endl;
    for (int i = 0; i < edges; i++) 
    {
        int vertex1, vertex2;
        std::cin>>vertex1>>vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1); 
    }

    int start_vertex;
    std::cout<<"Enter the start vertex : ";
    std::cin>>start_vertex;

    std::vector<int> res = bfs(graph, start_vertex);

    std::cout<<"BFS Traversal: ";
    for (int v : res) 
    {
        std::cout<<v<<" ";
    }
    return 0;
}

