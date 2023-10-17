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
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    int getSize();
    void print();
};

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
    cout << "Hola Crayola" << endl;
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

#endif /* Heap_h */