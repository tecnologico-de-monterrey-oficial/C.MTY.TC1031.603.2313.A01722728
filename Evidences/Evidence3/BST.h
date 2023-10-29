#ifndef BST_h
#define BST_h

#include "TNode.h"
#include <vector>

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
    void preorder(TNode<T>* aux);
    void inorder(TNode<T>* aux);
    void postorder(TNode<T>* aux);
    int getHeight(TNode<T>* aux);
    //void levelorder(TNode<T>* aux);
public:
    BST();
    void insert(T data);
    bool find(T data);
    int findAndCount(T data);
    bool remove(T data);
    void print();
    void visit(int type);
    int height();
    void ancestors(T data);
    int whatLevelamI(T data);
    bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    // Validamos si el arbol esta vacío
    if (isEmpty()) {
        // El está vacío
        // le asignamos a root un nuevo nodo con el valor de data
        root = new TNode<T>(data);
    } else {
        // El no esta vacío
        // Creamos un apuntador auxiliar igual a root
        TNode<T>* aux = root;
        // Recorremos el árbol hasta insertar el valor nuevo (aux != nullptr)
        while (aux != nullptr) {
            // Validamos si data es menor a aux->data
            if (data < aux->data) {
                // Si es menor
                // Validamos si el apundator del lado izquierdo de aux es nulo
                if (aux->left == nullptr) {
                    // Si es nulo
                    // Apuntamos al lado izquierdo de aux a un nuevo nodo con el valor de data
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // No es nulo
                    // Apuntamos aux al lado izquiero de aux
                    aux = aux->left;
                }
            } else {
                // Es mayor o igual 
                // Validamos si el apundator del lado derecho de aux es nulo
                if (aux->right == nullptr) {
                    // Si es nulo
                    // Apuntamos al lado izquierdo de aux a un nuevo nodo con el valor de data
                    aux->right = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // No es nulo
                    // Apuntamos aux al lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::find(T data) {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    while (aux != nullptr) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // Regresamos 
            return true;
        } else {
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // No lo encontramos
    return false;
}

template <class T>
int BST<T>::findAndCount(T data) {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    int cont = 0;
    while (aux != nullptr) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // Regresamos 
            cont++;
        }
        // Recorremos aux
        data < aux->data ? aux = aux->left : aux = aux->right;
    }
    // Return
    return cont;
}

template <class T>
int children(TNode<T>* aux) {
    // regresa la cantidad de hijos que tiene un nodo
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    }
    if (aux->left != nullptr && aux->right != nullptr) {
        return 2;
    }
    return 1;
}

template <class T>
bool BST<T>::remove(T data) {
    // buscar el nodo a borrar (debemos mantener un apuntador al papa del nodo a borrar)
    // Creamos un apuntador auxiliar padre igual a root
    TNode<T>* auxFather = root;
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    // hacemos una variable booleana para saber si encontramos el nodo
    bool found = false;
    while (!found) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // hacemo found igual a true
            found = true;
        } else {
            // Recorremos aux Father
            auxFather = aux;
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
            if (aux == nullptr) {
                // No se encuentra en el arbol
                return false;
            }
        }
    }
    // Buscamos cuantos hijos tiene el nodo
    int numChildren = children(aux);
    // 0 hijos
    if (numChildren == 0) {
        // Si el nodo a borrar es root
        if (aux == root) {
            // le asignamos nulos a root
            root = nullptr;
        } else { // El nodo no es root (else)
            aux->data < auxFather->data ? auxFather-> left = nullptr : auxFather-> right = nullptr;
            // Si el valor a borrar es menor al valor del padre
                // le asignamos nulos al apuntador del lado izquierdo del padre
            // Si el el valor es mayor o igual al valor del padre
                // le asignamos nulos al apuntador del lado derecho del padre
        }
        // borramos el nodo
        delete aux;
    }
    // 1 hijo
    if (numChildren == 1) {
        // Si el nodo a borrar es root
        if (aux == root) {
            aux->left != nullptr ? root = aux->left : root = aux->right;
            // Si el apuntador del lado izquierdo de root no es nulo (el hijo esta del lado izquierdo)
                // root va a ser igual al apuntador del lado izquierdo de root
            // si el apuntador del lado derecho de root no es nulo (el hijo esta del lado derecho)
                // root va a ser igual al apuntador del lado derecho de root
            // borramos el nodo que estaba en root
        } else { // Si el nodo a borrar no es root (else)
            // Si el valor del nodo a borrar es menor al valor del padre
            if (data < auxFather->data) {
                aux->left != nullptr ? auxFather->left = aux->left : auxFather->left = aux->right;
                // Si el apuntador del lado izquierdo del nodo a borrar no es nulo
                    // El apuntador del lado izquierdo del padre va a ser igual al apuntador del lado izquierdo del nodo a borrar
                // Si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                    // El apuntador del lado izquierdo del padre va a ser igual al apuntador del lado derecho del nodo a borrar
            } else {                    
            // Si el valor del nodo a borrar es mayor o igual al valor del padre (else)
                aux->left != nullptr ? auxFather->right = aux->left : auxFather->right = aux->right;
                // Si el apuntador del lado izquierdo del nodo a borrar no es nulo
                    // El apuntador del lado derecho del padre va a ser igual al apuntador del lado izquierdo del nodo a borrar
                // Si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                    // El apuntador del lado derecho del padre va a ser igual al apuntador del lado derecho del nodo a borrar
            }
        }
        // borramos el nodo
        delete aux;
    }
    // 2 hijos
    if (numChildren == 2) {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar es nulo (El hijo del lado izquierdo es el mayor)
        if (aux->left->right == nullptr) {
            // El valor del nodo a borrar va a ser igual al valor del hijo del lado izquierdo
            aux->data = aux->left->data;
            // Borramos el hijo del lado izquierdo del nodo a borrar
            TNode<T>* auxRemove = aux->left;
            // El apuntador del lado izquierdo del nodo a borrar va a ser igual al apuntador del lado izquierdo del hijo del lado izquierdo
            aux->left = aux->left->left;
            // Borramos el nodo
            delete auxRemove;
        } else {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar no es nulo (El hijo del lado izquierdo no es el mayor)
            // Creamos un apuntador auxiliar padre igual al hijo del lado izquierdo del nodo a borrar
            auxFather = aux->left;
            // Creamos un apuntador auxiliar hijo igual al apuntador del lado derecho del nodo auxiliar padre
            TNode<T>* auxChild = auxFather->right;
            // Iteramos mientras el apuntador del lado derecho del apuntador auxiliar hijo es diferente de nulo
            while (auxChild->right != nullptr) {
                // Reccorremos los apuntadores auxiliares
                // El apuntador auxiliar padre va a ser igual al apuntador auxiliar hijo
                auxFather = auxChild;
                // El apuntador auxiliar hijo va a ser igual al apuntador del lado derecho del apuntador auxiliar hijo
                auxChild = auxChild->right;
            }
            // El valor del nodo a borrar va a ser igual al valor del apuntador auxiliar hijo
            aux->data = auxChild->data;
            // El apuntador del lado derecho del auxiliar padre va a ser igual al apuntador del lado izquierdo del apuntador auxiliar hijo
            auxFather->right = auxChild->left;
            // Borramos el apuntador auxiliar hijo
            delete auxChild;
        }
    }
    return true;
}

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template <class T>
void BST<T>::preorder(TNode<T>* aux) {
    if (aux != nullptr) {
        cout << aux->data << "->";
        preorder(aux->left);
        preorder(aux->right);
    }
}

template <class T>
void BST<T>::inorder(TNode<T>* aux) {
    if (aux != nullptr) {
        inorder(aux->left);
        cout << aux->data << "->";
        inorder(aux->right);
    }
}

template <class T>
void BST<T>::postorder(TNode<T>* aux) {
    if (aux != nullptr) {
        postorder(aux->left);
        postorder(aux->right);
        cout << aux->data << "->";
    }
}

template <class T>
void BST<T>::visit(int type) {
    switch (type) {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
    cout << endl;
}

template <class T>
int BST<T>::getHeight(TNode<T>* aux) {
    if (aux == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(aux->left);
    int rightHeight = getHeight(aux->right);
    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

template <class T>
int BST<T>::height() {
    return getHeight(root);
}

template <class T>
void BST<T>::ancestors(T data) {
    //vector ancestros se usa como stack
    vector<T> ancestors;
    TNode<T>* aux = root;
    while (aux != nullptr) {
        if (data == aux->data) {
            aux = nullptr;
        } else {
            ancestors.push_back(aux->data);
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    cout << "Ancestors(farthest to closest): ";
    for (int i = 0; i < ancestors.size(); i++) {
        cout << ancestors[i] << "->";
    }
    cout << endl;
}



template <class T>
int BST<T>::whatLevelamI(T data) {
    int level = 0;
    TNode<T>* aux = root;
    while (aux != nullptr) {
        if (data == aux->data) {
            return height()-level;
        } else {
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
            level++;
        }
    }
    return -1;
}

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

#endif /* BST_h */