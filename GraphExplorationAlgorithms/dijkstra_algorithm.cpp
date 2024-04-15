//A C++ program for Dijkstra's single source shortest path using adjacency matrix 
#include<iostream>
#include<vector>

//find the minimum distance from the source to other vertices, which are not yet visited.
int minDistance(std::vector<int> dist, std::vector<bool> visited, int vertices)
{
	// Initialize min value
	int min = INT_MAX, min_index;
	//Iterated through all vertices in the graph
	for (int i = 0; i < vertices; i++)
	{
		//if distance from source < current minimum, 
		if (!visited[i] && dist[i] <= min)
		{
			min = dist[i], min_index = i;
		}
	}

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(std::vector<int> dist, int n)
{
	std::cout<<"Distance from Source"<<std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout<<i<<" -> "<<dist[i]<<std::endl;
	}

}

//Find the shportest paths from single source to all other vertices
void dijkstra(std::vector<std::vector<int>>& graph, int src)
{
	int vertices = graph.size();
	std::vector<int> dist(vertices, INT_MAX);
	std::vector<bool> visited(vertices, false);

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find the vertex with minimum distance out of all vertices not yet visited
	for (int count = 0; count < vertices - 1; count++) 
	{
		//store the minimum vertex index in u
		int u = minDistance(dist, visited, vertices);

		// Mark the picked vertex as visited
		visited[u] = true;

		//update the distance of the neighbouring vertices of 
		//the above selected vertex if a shorter path is found
		//through the above min vertex index
		for (int i = 0; i < vertices; i++)

			if (!visited[i] && graph[u][i] && dist[u] != INT_MAX
				&& dist[u] + graph[u][i] < dist[i])
				dist[i] = dist[u] + graph[u][i];
	}

	// print the constructed distance array
	printSolution(dist, vertices);
}

int main()
{
	int vertices = 0, source = 0;
	std::cout<<"Enter number of vertices : "<<std::endl;
	std::cin>>vertices;
	
	std::vector<std::vector<int>> graph(vertices, std::vector<int>(vertices, 0)); 
	
	std::cout<<"Enter the source vertex : "<<std::endl;
	std::cin>>source;
	std::cout<<"Enter the adjacency matrix. Enter 0 if there is no path : "<<std::endl;
	for(int i = 0; i < vertices; i++)
	{
	    for(int j = 0; j < vertices; j++)
	    {
		    std::cin>>graph[i][j];
	    }
	}
	

	/*Example input =
	 * number of vertices : 5
	 * source vertex : 0
	 * Enter the adjacency matrix. Enter 0 if there is no path : 
	 * 0 6 3 0 0
	 * 6 0 1 4 0
	 * 3 1 0 0 5
	 * 0 4 0 0 2
	 * 0 0 5 2 0
	*/
	dijkstra(graph, source);

	return 0;
}

