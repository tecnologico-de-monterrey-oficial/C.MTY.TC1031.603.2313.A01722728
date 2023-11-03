#ifndef GraphM_h
#define GraphM_h

#include "Edge.h"

template <class T>
class GraphM {
private:
    vector<T> vertices;
    vector< vector<bool> > matrix;
    int findVertex(T vertex);
public:
    GraphM();
    GraphM(vector<T> vertices, vector< Edge<T> > edges);
    void print();
};

template <class T>
GraphM<T>::GraphM() {

}

template <class T>
int GraphM<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}


template <class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Edge<T> > edges) {
    // Actualizar la lista de vertices con los vertices que recibimos de parámetro
    this->vertices = vertices;
    // inicializamos la matriz con falso en todas las posiciones
    vector<bool> rows(vertices.size(),false);
    matrix.assign(vertices.size(), rows);
    // Iteramos la lista de arcos
    for (auto edge : edges) {
        // Encontramos el índice en la lista de vértices del vértice origen
        int sourceIndex = findVertex(edge.source);
        // Encontramos el índice en la lista de vértic es del vértice destino
        int targetIndex = findVertex(edge.target);
        // Actualizamos en verdadero en la matriz en el renglon del indice origen y en la columna del indice destino
        if (sourceIndex != -1 && targetIndex != -1) {
            matrix[sourceIndex][targetIndex] = true;
        }

    }
}

template <class T>
void GraphM<T>::print() {
    cout << "   ";
    for (auto vertex : vertices) {
        cout << " " << vertex;
    }
    cout << endl;
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (int j=0; j<vertices.size(); j++) {
            if (matrix[i][j]) {
                cout << "T";
            } else {
                cout << "F";
            }
            cout << " ";
        }
        cout << endl;
    }
}


#endif /* GraphM_h */