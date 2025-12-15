#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>   // para std::ostream

// Nodo de un Árbol Binario de Búsqueda
template <typename T>
class BSNode {
public:
    T elem;              // elemento del nodo
    BSNode<T>* left;     // puntero al nodo izquierdo
    BSNode<T>* right;    // puntero al nodo derecho

   
    BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr){
	    this->elem = elem;
	    this->left = left;
	    this->right = right;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const BSNode<U> &bsn);
};

template <typename U>
std::ostream& operator<<(std::ostream &out, const BSNode<U> &bsn) {
    out << bsn.elem;
    return out;
}

#endif // BSNODE_H

