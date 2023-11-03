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
}


#endif /* GraphMW_h */