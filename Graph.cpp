#include "Graph.h"
Graph::Graph(int ver)
{
    //Gets number of vertices and make a adjacency matrix
    v = ver;
    int i, j;
    adjMat = new int *[v];

    for (i = 0; i < v; ++i)
        adjMat[i] = new int[v];

    for (int i = 0; i < v; ++i)
        for (int j = 0; j < v; ++j)
            adjMat[i][j] = 0;
}
void Graph::addEdge(int u, int v, int w)
{
    adjMat[u][v] = w;
}
void Graph::printMat()
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            std::cout << adjMat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int Graph::minDistance(int *dist, bool *is_visited)
{
    int min = INT_MAX, min_index;

    for (int ver = 0; ver < v; ver++)
        if (is_visited[ver] == false && dist[ver] <= min)
            min = dist[ver], min_index = ver;

    return min_index;
}

// A utility function to print the constructed distance array
int Graph::printDist(int *dist, int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < v; i++)
    {
        switch (i)
        {
        case 0:
            std::cout << " a \t\t " << dist[i] << std::endl;
            break;
        case 1:
            std::cout << " b \t\t " << dist[i] << std::endl;
            break;
        case 2:
            std::cout << " c \t\t " << dist[i] << std::endl;
            break;
        case 3:
            std::cout << " d \t\t " << dist[i] << std::endl;
            break;
        case 4:
            std::cout << " e \t\t " << dist[i] << std::endl;
            break;
        case 5:
            std::cout << " z \t\t " << dist[i] << std::endl;
            break;

        default:
            break;
        }
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Graph::dijkstra(int **graph, int src)
{
    //Array to hold distance from src
    int dist[v];
    //will be true if a node is visited
    bool is_visited[v];

    // Initialize all distances as INFINITE and is_visited[] as false
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX, is_visited[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    for (int count = 0; count < v - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices
        int u = minDistance(dist, is_visited);

        //mark as true
        is_visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int ver = 0; ver < v; ver++)
            if (!is_visited[ver] && graph[u][ver] && dist[u] != INT_MAX && dist[u] + graph[u][ver] < dist[ver])
                dist[ver] = dist[u] + graph[u][ver];
    }
    //print distances calculated
    printDist(dist, v);
}