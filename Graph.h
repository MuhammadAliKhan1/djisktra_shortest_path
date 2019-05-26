#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <climits>
class Graph
{
private:
public:
    int v;
    int **adjMat; //Adjacency matrix
    Graph(int);
    void addEdge(int, int, int);
    void printMat();
    void dijkstra(int **, int);
    int minDistance(int *, bool*);
    int printDist(int *, int);
};
#endif //GRAPH_H