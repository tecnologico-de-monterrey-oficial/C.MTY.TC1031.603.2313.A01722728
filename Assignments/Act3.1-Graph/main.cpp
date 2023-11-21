#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#include "GraphMW.h"
#include "Graph.h"


int main() {
    vector<string> menu{
        "addVertex",
        "addEdge",
        "removeVertex",
        "removeEdge",
        "print",
        "exit"
    };
    int option = 0;
    string operation = "";

    Graph<int> graph;
    GraphMW<int> graphMW;

    while(operation!="exit"){
        cout << "Select an option:" << endl;
        for(int i = 0; i < menu.size(); i++){
            cout << i << ". " << menu[i] << endl;
        }
        cin >> option;
        operation = menu[option%menu.size()];
        //if else logic with exception handling when applying the functions
        if(operation == "addVertex"){
            int vertex;
            cout << "Enter vertex: ";
            cin >> vertex;
            //exception handling
            try{
                graph.addVertex(vertex);
                graphMW.addVertex(vertex);
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "addEdge"){
            int source, target, weight;
            cout << "Enter source: ";
            cin >> source;
            cout << "Enter target: ";
            cin >> target;
            cout << "Enter weight: ";
            cin >> weight;
            //exception handling
            try{
                graph.addEdge(Edge<int>(source, target, weight));
                graphMW.addEdge(Edge<int>(source, target, weight));
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "removeVertex"){
            int vertex;
            cout << "Enter vertex: ";
            cin >> vertex;
            //exception handling
            try{
                graph.removeVertex(vertex);
                graphMW.removeVertex(vertex);
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "removeEdge"){
            int source, target;
            cout << "Enter source: ";
            cin >> source;
            cout << "Enter target: ";
            cin >> target;
            //exception handling
            try{
                graph.removeEdge(Edge<int>(source, target));
                graphMW.removeEdge(Edge<int>(source, target));
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(operation == "print"){
            cout << "List Graph:" << endl;
            graph.print();
            cout << "Matrix Weighted Graph:" << endl;
            graphMW.print();
        }
    }

    return 0;
}