#ifndef Graph_h
#define Graph_h

template <class T>
class Graph {
private:
    vector<T> vertices;
    vector< vector< Edge<T> > > adjacencyList;
    int findVertex(T vertex);
public:
    Graph();
    Graph(vector<T> vertices, vector< Edge<T> > edges);
    void print();
};






#endif /* Graph_h */