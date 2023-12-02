#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include <queue>
#include <stack>

template <class T>
class Graph {
private:
    vector<T> vertices;
    vector< vector< Edge<T> > > adjacencyList;
    int findVertex(T vertex);
    void dfsr(T vertex, vector<bool> &status);
    int findShortest(vector<bool> &status, vector<int> &cost);
public:
    Graph();
    Graph(vector<T> vertices, vector< Edge<T> > edges);
    void addVertex(T vertex);
    void addEdge(Edge<T> egde);
    void removeVertex(T vertex);
    void removeEdge(Edge<T> edge);
    void bfs(T vertex);
    void dfs(T vertex);
    void dijkstra(T vertex);
    void print();
};

template <class T>
Graph<T>::Graph() {

}

template <class T>
int Graph<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template <class T>
Graph<T>::Graph(vector<T> vertices, vector< Edge<T> > edges) {
    // Actualizamos la lista de vértices
    this->vertices = vertices;
    // Inicilizamos la lista de adyacencias
    adjacencyList.resize(vertices.size());
    // Recorremos la lista adyacencias
    for (auto edge : edges) {
        // buscamos el índice en la lista de vértices del vértice origen
        int sourceIndex = findVertex(edge.source);
        // buscamos el índice en la lista de vértices del vértice destino
        int targetIndex = findVertex(edge.target);
        // Validamos que existan en la lista de vértices
        if (sourceIndex != -1 && targetIndex != -1) {
            adjacencyList[sourceIndex].push_back(edge);
        }
    }
}

template <class T>
void Graph<T>::addVertex(T vertex) {
    // Buscar si existe el vértice a agregar
    int vertexIndex = findVertex(vertex);
    // Si no existe agregarlo a la lista de vértices
    if (vertexIndex == -1) {
        // Lo agregamos a la lista de vértices
        vertices.push_back(vertex);
        // Agregarlo a la lista de adyacencias
        vector< Edge<T> > emptyEdges;
        adjacencyList.push_back(emptyEdges);
    } else {
        throw invalid_argument("Vértice ya existe");
    }
}

template <class T>
void Graph<T>::addEdge(Edge<T> edge) {
    // Validar que los vértices origen y destino existan
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    // Validar que el edge no se encuentre ya en la lista de adyacencias
    if (sourceIndex != -1 && targetIndex != -1) {
        for (auto neighbor : adjacencyList[sourceIndex]) {
            // Validamos que no exisa ya en la lista de adyacencias
            if (neighbor.target == edge.target) {
                throw invalid_argument("El arco ya existe");
            }
        }
        // Agregar el edge a la lista de ayacencias
        adjacencyList[sourceIndex].push_back(edge);
    } else {
        throw invalid_argument("Alguno de los vértices no existen");
    }
}

template <class T>
void Graph<T>::removeVertex(T vertex) {
    // Buscar el índice del vértice a borrar
    int vertexIndex = findVertex(vertex);
    // Si existe, borrar en la lista de adyacencias todos los arcos que tienen ese vértice
    if (vertexIndex != -1) {
        // Recorremos la lista de adyacencias
        for (int i=0; i<adjacencyList.size(); i++) {
            // Recorremos la lista de arcos
            for (int j=0; j<adjacencyList[i].size(); j++) {
                // Validamos si el target del arco es igual al vértice a borrar
                if (adjacencyList[i][j].target == vertex) {
                    // Borramos el arco
                    adjacencyList[i].erase(adjacencyList[i].begin() + j);
                }
            }
        }
        // Borrar el vértice de la lista de vértices
        vertices.erase(vertices.begin() + vertexIndex);
        // Borrar el vértice de la lista de adyacencias
        adjacencyList.erase(adjacencyList.begin() + vertexIndex);
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

template <class T>
void Graph<T>::removeEdge(Edge<T> edge) {
    // buscar el índice del vértice origen
    int sourceIndex = findVertex(edge.source);
    // Si existe, buscar en la lista de adyacencias el edge
    if (sourceIndex != -1) {
        // Recorremos la lista de arcos
        for (int i=0; i<adjacencyList[sourceIndex].size(); i++) {
            // Validamos si el target del arco es igual al vértice a borrar
            if (adjacencyList[sourceIndex][i].target == edge.target) {
                // Borramos el arco
                adjacencyList[sourceIndex].erase(adjacencyList[sourceIndex].begin() + i);
            }
        }
    } else {
        throw invalid_argument("El vértice origen no existe");
    }
}

template <class T>
void Graph<T>::bfs(T vertex) {
    // validamos que el vértice de inicio exista
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos una lista de estados del tamaño de la cantidad de vértices inicializado en falso
        vector<bool> status(vertices.size(), false);
        // Creamos una cola para guardar los vértices a visitar
        queue<T> queue;
        // Agregamos el vértice de inicio a la cola
        queue.push(vertex);
        // Actualizamos el estado del vértice de inicio
        status[vertexIndex] = true;
        // Iteramos mientras la cola no esté vacía
        while (!queue.empty()) {
            // Sacamos el primer elemento de la cola
            T currentVertex = queue.front();
            // Imprimimos el vértice
            cout << currentVertex << " ";
            // Sacamos el vértice de la cola
            queue.pop();
            // Buscamos el índice del vértice
            int currentVertexIndex = findVertex(currentVertex);
            // Recorremos todos los vecinos del vértice
            for (auto neighbor : adjacencyList[currentVertexIndex]) {
                // Buscamos el índice del vecino
                int neighborIndex = findVertex(neighbor.target);
                // Validamos el estado del vecino
                if (!status[neighborIndex]) {
                    // Agregamos el vecino a la cola
                    queue.push(neighbor.target);
                    // Actualizamos el estado del vecino
                    status[neighborIndex] = true;
                }
            }
        }
        cout << endl;
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

template <class T>
void Graph<T>::dfsr(T vertex, vector<bool> &status) {
    // Visitamos el vértice
    cout << vertex << " ";
    // Buscamos el índice del vértice
    int vertexIndex = findVertex(vertex);
    // Actualizamos su estado
    status[vertexIndex] = true;
    // Recorremos todos sus vecinos
    for (auto neighbor : adjacencyList[vertexIndex]) {
        // Obtenemos el índice del vecino
        int neighborIndex = findVertex(neighbor.target);
        // Validamos su estado
        if (!status[neighborIndex]) {
            // Llamamos al dfsr
            dfsr(neighbor.target, status);
        }
    }
}

template <class T>
void Graph<T>::dfs(T vertex) {
    // Validamos si el vértice existe
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos una lista de estado del tamaño de la cantidad de vértices inicializado en falso
        vector<bool> status(vertices.size(), false);
        // Llamamos a la función de recursividad
        dfsr(vertex, status);
    } else {
        throw invalid_argument("Vértice inválido");
    }
}

template <class T>
int Graph<T>::findShortest(vector<bool> &status, vector<int> &cost) {
    // Incializamos una variable en -1 para guardar el índice del costo más pequeño
    int shortestIndex = -1;
    // Inicializamos una variable para determinar cual fue el costo más pequeño
    int shortestCost = INT_MAX;
    // Iteramos todos los vértices
    for (int i=0; i<vertices.size(); i++) {
        // Validamos que el estatus del vértice actual sea falso
        if (!status[i]) {
            // Comparamos si el costo de vértice actual es menor al costo más pequeño
            if (cost[i] < shortestCost) {
                // Actualizamos el shortest Cost
                shortestCost = cost[i];
                // Actualizamos el shortest Index
                shortestIndex = i;
            }
        }
    }
    return shortestIndex;
}

template <class T>
void Graph<T>::dijkstra(T vertex) {
    // Validamos que el vértice de parámetro exista
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos la tabla de estados
        vector<bool> status(vertices.size(), false);
        // Creamos la tabla de costos
        vector<int> cost(vertices.size(), INT_MAX);
        // Creamos la tabla de path
        vector<int> path(vertices.size(), -1);
        // Actualizamos el costo en 0 del vértice inicio
        cost[vertexIndex] = 0;
        // Creamos una varibale para guardar cual el fue el vertice más pequeño de los que tienen estado en falso
        int shortestIndex = vertexIndex;
        // Iteramos mientras existe un vértice con estado en falso
        while (shortestIndex != -1) {
            // Actualizamos el estado del shortestIndex
            status[shortestIndex] = true;
            // Recorremos los vecinos del shortestIndex
            for (auto neighbor : adjacencyList[shortestIndex]) {
                // Buscamos el índice del vecino
                int neighborIndex = findVertex(neighbor.target);
                // Validamos el estado del vecino
                if (!status[neighborIndex]) {
                    // Validamos si el costo del vecino sea mayor que el costo del shortestIndex más el peso del vecino
                    if (cost[neighborIndex] > cost[shortestIndex] + neighbor.weight) {
                        // Actualizo el costo del vecino
                        cost[neighborIndex] = cost[shortestIndex] + neighbor.weight;
                        // Actualizamos el path del vecino
                        path[neighborIndex] = shortestIndex;
                    }
                }
            }
            // Actualizamos el valor de shortest Index
            shortestIndex = findShortest(status, cost);
        }
        // Seguimos con el proceso de actualizar la lista de pilas
        // Incializamos una lista de pilas vacías
        vector< stack<int> > shortestPaths(vertices.size());
        // Recorremos todos los vértices
        for (int i=0; i<vertices.size(); i++) {
            // Valdamos que el costo no sea infinito
            if (cost[i] != INT_MAX) { 
                // Agregamos la pila del vértice actual su índice
                shortestPaths[i].push(i);
                // Creamos ubna variable para guardar el índice del path
                int pathIndex = path[i];
                // Iteramos mientras pathIndex sea diferente de -1
                while (pathIndex != -1) {
                    // Agregamos el path index a la pila
                    shortestPaths[i].push(pathIndex);   
                    // Actualizamos el path index con el valor del path de path index
                    pathIndex = path[pathIndex];
                }
            }
        }
        // Imprimimos el resultado
        // Iteramos todos los vértices
        for (int i=0; i<vertices.size(); i++) {
            cout << vertices[i] << " -> ";
            // Valid[amos que la pila no sea vacía o que el costo no sea infinito
            if (cost[i] != INT_MAX) {
                // Iteramos mientas la pila no sea vacía
                while (!shortestPaths[i].empty()) {
                    // Imprimimos el primer elemento de la pila
                    cout << shortestPaths[i].top() << " ";
                    // Sacamos el primer elemento de la pila
                    shortestPaths[i].pop();
                }
                // Imprimimos el peso
                cout << "- " << cost[i] << endl;
            } else {
                cout << "No hay ruta" << endl;
            }
        }
    } else {
        throw invalid_argument("El vértice no existe");
    }
}

template <class T>
void Graph<T>::print() {
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (auto edge : adjacencyList[i]) {
            cout << edge.target << " " << edge.weight << " - ";
        }
        cout << endl;
    }
    cout << endl;
}






#endif /* Graph_h */