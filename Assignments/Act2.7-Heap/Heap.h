#ifndef Heap_h
#define Heap_h

template <class T>
class Heap{
    private:
        vector<T> Heap;
        void swap(int a, int b);
    public:
        Heap();
        Heap(vector<t> list);
        Heap(initializer_list<T> list);
        int getSize();
        void print();
};

template <class T>
Heap<T>::Heap(){

}

template <class T>
void HEAP<T>::swap(){
    T aux = haep[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
Heap<T>::Heap(vector<T> list){
    heap = list;
    int auxFather = heap.size()/2 - 1;
    while(auxFather >= 0){
        int father = auxFather;
        int son1;
        int son2;
        int big;
        while(father * 2 + 1 < heap.size()){
            son1 = father*2 + 1;
            if(father * 2 + 2 < heap.size()){
                son2 = father*2 + 2;
                heap[son1] > heap[son2] ? big = son1 : big = son2;
            }else{
                big = son1;
            }
            if(heap[father] < heap[big]){
                swap(father, big);
                father = big;
            }else {
                father = heap.size();
            }         

        auxFather--;
    }

}




#endif


