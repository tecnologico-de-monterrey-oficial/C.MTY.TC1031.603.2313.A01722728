#ifndef GraphMW_h
#define GraphMW_h

#include "Edge.h"

template <class T>
class GraphMW {
private:
    vector<T> vertices;
    vector< vector<int> > matrix;
    int findVertex(T vertex);
public:
    GraphMW();
    GraphMW(vector<T> vertices, vector< Edge<T> > edges);
    void addVertex(T vertex);
    void addEdge(Edge<T> egde);
    void removeVertex(T vertex);
    void removeEdge(Edge<T> edge);
    void print();
};

template <class T>
GraphMW<T>::GraphMW() {

}

template <class T>
int GraphMW<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}


template <class T>
GraphMW<T>::GraphMW(vector<T> vertices, vector< Edge<T> > edges) {
    // Actualizar la lista de vertices con los vertices que recibimos de parámetro
    this->vertices = vertices;
    // inicializamos la matriz con falso en todas las posiciones
    vector<int> rows(vertices.size(),0);
    matrix.assign(vertices.size(), rows);
    // Iteramos la lista de arcos
    for (auto edge : edges) {
        // Encontramos el índice en la lista de vértices del vértice origen
        int sourceIndex = findVertex(edge.source);
        // Encontramos el índice en la lista de vértic es del vértice destino
        int targetIndex = findVertex(edge.target);
        // Actualizamos en verdadero en la matriz en el renglon del indice origen y en la columna del indice destino
        if (sourceIndex != -1 && targetIndex != -1) {
            matrix[sourceIndex][targetIndex] = edge.weight;
        }

    }
}

template <class T>
void GraphMW<T>::addVertex(T vertex) {
    // Verificamos que el vértice no exista en la lista de vértices
    if (findVertex(vertex) == -1) {
        // Agregamos el vértice a la lista de vértices
        vertices.push_back(vertex);
        // Agregamos una columna a la matriz
        for (int i=0; i<matrix.size(); i++) {
            matrix[i].push_back(0);
        }
        // Agregamos un renglón a la matriz
        vector<int> row(vertices.size(),0);
        matrix.push_back(row);
    } else {
        throw runtime_error("Vertex already exists");
    }
    
}

template <class T>
void GraphMW<T>::addEdge(Edge<T> edge) {
    // Encontramos el índice en la lista de vértices del vértice origen
    int sourceIndex = findVertex(edge.source);
    // Encontramos el índice en la lista de vértices del vértice destino
    int targetIndex = findVertex(edge.target);
    // Actualizamos en verdadero en la matriz en el renglon del indice origen y en la columna del indice destino
    if (sourceIndex != -1 && targetIndex != -1) {
        matrix[sourceIndex][targetIndex] = edge.weight;
    } else {
        throw runtime_error("Source or target vertex does not exist");
    }
    
}

template <class T>
void GraphMW<T>::removeVertex( T vertex) {
    // Encontramos el índice en la lista de vértices del vértice origen
    int vertexIndex = findVertex(vertex);
    // Verificamos que el vértice exista en la lista de vértices
    if (vertexIndex != -1) {
        // Eliminamos el vértice de la lista de vértices
        vertices.erase(vertices.begin()+vertexIndex);
        // Eliminamos el renglón de la matriz
        matrix.erase(matrix.begin()+vertexIndex);
        // Eliminamos la columna de la matriz
        for (int i=0; i<matrix.size(); i++) {
            matrix[i].erase(matrix[i].begin()+vertexIndex);
        }
    } else {
        throw runtime_error("Vertex does not exist");
    }
    
}

template <class T>
void GraphMW<T>::removeEdge( Edge<T> edge) {
    // Encontramos el índice en la lista de vértices del vértice origen
    int sourceIndex = findVertex(edge.source);
    // Encontramos el índice en la lista de vértices del vértice destino
    int targetIndex = findVertex(edge.target);
    // Actualizamos en verdadero en la matriz en el renglon del indice origen y en la columna del indice destino
    if (sourceIndex != -1 && targetIndex != -1) {
        matrix[sourceIndex][targetIndex] = 0;
    } else {
        throw runtime_error("Source or target vertex does not exist");
    }   
}

template <class T>
void GraphMW<T>::print() {
    cout << "   ";
    for (auto vertex : vertices) {
        cout << " " << vertex;
    }
    cout << endl;
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (int j=0; j<vertices.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


#endif /* GraphMW_h */