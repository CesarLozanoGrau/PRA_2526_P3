#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T>
class BSTree
{
private:
    int nelem;
    BSNode<T> *root;
    BSNode<T> *search(BSNode<T> *n, T e) const
    {
        if (n == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->elem < e)
        {
            return search(n->right, e);
        }
        else if (n->elem > e)
        {
            return search(n->left, e);
        }
        else
        {
            return n;
        }
    }
    BSNode<T> *insert(BSNode<T> *n, T e)
    {
        if (n == nullptr)
        {
            return new BSNode<T>(e);
        }
        else if (n->elem == e)
        {
            throw runtime_error("Elemento ya existente");
        }
        else if (n->elem < e)
        {
            n->right = insert(n->right, e);
        }
        else
        {
            n->left = insert(n->left, e);
        }
        return n;
    }
    void print_inorder(ostream &out, BSNode<T> *n) const
    {
        if (n == nullptr)
        {
            return;
        }
        print_inorder(out, n->left);
        out << n->elem << " ";
        print_inorder(out, n->right);
    }
    BSNode<T> *remove(BSNode<T> *n, T e)
    {
        if (n == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->elem < e)
        {
            n->right = remove(n->right, e);
        }
        else if (n->elem > e)
        {
            n->left = remove(n->left, e);
        }
        else
        {
            if (n->left != nullptr && n->right != nullptr)
            {
                n->elem = max(n->left);
                n->left = remove_max(n->left);
            }
            else
            {
                BSNode<T> *temp = n;
                n = (n->left != nullptr) ? n->left : n->right;
                delete temp;
            }
        }
        return n;
    }
    T max(BSNode<T> *n) const
    {
        if (n == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->right != nullptr)
        {
            return max(n->right);
        }
        else
        {
            return n->elem;
        }
    }
    BSNode<T> *remove_max(BSNode<T> *n)
    {
        if (n->right == nullptr)
        {
            BSNode<T> *temp = n;
            n = n->left;
            delete temp;
        }
        else
        {
            n->right = remove_max(n->right);
        }
        return n;
    }
    void delete_cascade(BSNode<T> *n)
    {
        if (n != nullptr)
        {
            delete_cascade(n->left);
            delete_cascade(n->right);
            delete n;
        }
    }

public:

    BSTree(){
        this->root = nullptr;
        this->nelem = 0;
    }
    int size() const
    {
        return nelem;
    }
    void insert(T e)
    {
        root = insert(root, e);
        nelem++;
    }
    T search(T e) const
    {
        return search(root, e)->elem;
    }
    friend ostream &operator<<(ostream &out, const BSTree<T> &bst)
    {
        bst.print_inorder(out, bst.root);
        return out;
    }
    void remove(T e)
    {
        root = remove(root, e);
        nelem--;
    }
    ~BSTree()
    {
        delete_cascade(root);
    }
};
#endif