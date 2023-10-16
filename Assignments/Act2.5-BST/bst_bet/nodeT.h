#ifndef NODET_H
#define NODET_H

template <typename T>
class nodeT {
  private:
    T data;
    nodeT<T> *left,*right;
  public:
    nodeT();
    nodeT(T);
    T Data() {return data;}
    nodeT<T>* Left() {return left;}
    nodeT<T>* Right() {return right;}
    void setData(T _data) {data = _data;}
    void setLeft(nodeT<T>* p) {left = p;}
    void setRight(nodeT<T>* p) {right = p;}
};

template <typename T>
nodeT<T>::nodeT() {
    left = right = NULL;
}

template <typename T>
nodeT<T>::nodeT(T data) {
    this->data = data; // ocurre enmascaramiento de la variable data
    left = right = NULL;
}

#endif