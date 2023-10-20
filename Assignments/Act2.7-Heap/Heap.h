#ifndef Heap_h
#define Heap_h

#include <vector>

template <class T>
class Heap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    vector<T> getHeap();
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    T pop(); // Elimina al elemento de mayor prioridad
    T top();
    void push(T data);
    int getSize();
    void print();
    bool isEmpty();
};

template <class T>
vector<T> Heap<T>::getHeap()
{
    return heap;
}

template <class T>
Heap<T>::Heap()
{
}

template <class T>
void Heap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father)
{
    // definimos variables para los hijos
    int son1;
    int son2;
    int big;
    // Recorremos mientras father tenga hijos
    while (father * 2 + 1 < heap.size())
    {
        // Calculamos el índice del primer
        son1 = father * 2 + 1;
        // Validamos si hay un segundo hijo
        if (father * 2 + 2 < heap.size())
        {
            // Asignamos el índice del segundo hijo
            son2 = father * 2 + 2;
            // Validamos cual de los dos hijos es mayor
            heap[son1] > heap[son2] ? big = son1 : big = son2;
        }
        else
        {
            // el único hijo es el mas grande
            big = son1;
        }
        // Validamos si el mpás grande de los hijos es mayor al padre
        if (heap[big] > heap[father])
        {
            // Los intercambiamos
            swap(father, big);
            // Hacemos el padre igual al mayor de los hijos
            father = big;
        }
        else
        {
            // Nos salimos del ciclo
            father = heap.size();
        }
    }
}

template <class T>
Heap<T>::Heap(vector<T> list)
{
    // Asignamos el valor de la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = heap.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Hago el ordenamiento hacia abajo
        downSort(father);
        // recorremos al siguiente padre de derecha a izquierda
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list)
{
    // Asignamos el valor de la lista al heap
    heap = list;
    // Encontramos el último de los padres
    int father = heap.size() / 2 - 1;
    // Recorremos todos los padres de derecha a izquierda
    while (father >= 0)
    {
        // Hago el ordenamiento hacia abajo
        downSort(father);
        // recorremos al siguiente padre de derecha a izquierda
        father--;
    }
}

template <class T>
T Heap<T>::pop()
{
    if (!heap.empty())
    {
        // Creamos una variable auxiliar para regresar el elemento de mayor prioridad del heap
        T aux = heap[0];
        // Intercambiamos el elemento de mayor prioridad con el último elemento
        swap(0, heap.size() - 1);
        // Borramos el último elemento de la lista
        heap.pop_back();
        // Reacomodamos hacia abajo el primer elemento
        downSort(0);
        // regresamos el valor de mayor prioridad
        return aux;
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template <class T>
T Heap<T>::top()
{
    if (!heap.empty())
    {
        return heap[0];
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template <class T>
void Heap<T>::push(T data){
    heap.push_back(data);
    int son = heap.size() - 1;

    //recorremos sus ancestros
    while(son>0){
        int father = (son-1)/2;
        if(heap[father]<heap[son]){
            swap(father,son);
            son = father;
        } else {
            son = 0;
        }
    }
}

template <class T>
int Heap<T>::getSize()
{
    return heap.size();
}

template <class T>
void Heap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
bool Heap<T>::isEmpty()
{
    return heap.empty();
}

#endif /* Heap_h */