#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "GraphM.h"
#include "GraphMW.h"
#include "Graph.h"


int main() {
    /*
    vector<string> vertices = {"A", "B", "C", "D", "E"};
    vector< Edge<string> > edges;
    edges.emplace_back("A","B");
    edges.emplace_back("B","A");
    edges.emplace_back("A","C");
    edges.emplace_back("C","A");
    edges.emplace_back("A","E");
    edges.emplace_back("E","A");
    edges.emplace_back("B","D");
    edges.emplace_back("D","B");
    edges.emplace_back("C","D");
    edges.emplace_back("D","C");
    edges.emplace_back("E","D");
    edges.emplace_back("D","E");

    GraphM<string> graphM(vertices, edges);
    graphM.print();
    */

    vector<int> vertices = {0,1,2,3,4,5,6,7};
    vector< Edge<int> > edges;
    edges.emplace_back(0,2,9);
    edges.emplace_back(0,3,9);
    edges.emplace_back(1,0,7);
    edges.emplace_back(2,0,9);
    edges.emplace_back(2,1,5);
    edges.emplace_back(2,6,7);
    edges.emplace_back(3,1,8);
    edges.emplace_back(3,7,1);
    edges.emplace_back(4,2,7);
    edges.emplace_back(4,6,9);
    edges.emplace_back(5,1,1);
    edges.emplace_back(5,3,9);
    edges.emplace_back(6,4,3);
    edges.emplace_back(7,5,2);

    Graph<int> graph(vertices, edges);
    graph.print();
    graph.addVertex(8);
    graph.addEdge(Edge<int>(8,0,5));
    graph.addEdge(Edge<int>(0,8,5));
    
    graph.print();
    
    


    graph.removeVertex(1);
    graph.removeEdge(Edge<int>(2,1,5));
    graph.print();
    //graph.bfs(0);
    cout << endl;
    //graph.dfs(0);
    cout << endl;
    //graph.dijkstra(0);





    return 0;
}