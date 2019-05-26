#include "Graph.h"
int main()
{
    //0 = a , 1 = b, 2 = c , 3 = d, 4 = e, 5 = z

    Graph *obj = new Graph(6);
    obj->addEdge(0, 0, 0);
    obj->addEdge(0, 1, 4);
    obj->addEdge(0, 2, 2);

    obj->addEdge(1, 1, 0);
    obj->addEdge(1, 0, 4);
    obj->addEdge(1, 2, 1);

    obj->addEdge(2, 2, 0);
    obj->addEdge(2, 0, 2);
    obj->addEdge(2, 1, 1);
    obj->addEdge(2, 3, 8);
    obj->addEdge(2, 4, 10);

    obj->addEdge(3, 3, 0);
    obj->addEdge(3, 1, 5);
    obj->addEdge(3, 2, 8);
    obj->addEdge(3, 4, 2);
    obj->addEdge(3, 5, 6);

    obj->addEdge(4, 4, 0);
    obj->addEdge(4, 2, 10);
    obj->addEdge(4, 3, 2);
    obj->addEdge(4, 5, 5);

    obj->addEdge(5, 5, 0);
    obj->addEdge(5, 3, 6);
    obj->addEdge(5, 4, 5);
    obj->dijkstra(obj->adjMat, 0);
}