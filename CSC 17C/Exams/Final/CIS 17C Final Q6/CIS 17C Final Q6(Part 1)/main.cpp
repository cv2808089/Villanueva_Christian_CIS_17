#include <iostream>
#include "Graph.h"
using namespace std;

int main(int argc, char** argv) 
{
    Graph g(7);
    g.addEdge(0,1,2702);
    g.addEdge(0,2,1846);
    g.addEdge(2,1,867);
    g.addEdge(2,3,742);
    g.addEdge(3,1,189);
    g.addEdge(0,4,1464);
    g.addEdge(4,2,802);
    g.addEdge(4,5,1123);
    g.addEdge(5,3,1092);
    g.addEdge(5,1,1258);
    g.addEdge(0,6,339);
    g.addEdge(6,4,1235);
    g.addEdge(6,5,2342);
    
    
    g.shortestPath(2);
    cout << endl << endl;
    g.shortestPath(3);
    return 0;
}

