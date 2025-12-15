#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V>
{
private:
    BSTree<TableEntry<V>> *tree;

public:
    BSTreeDict()
    {
        tree = new BSTree<TableEntry<V>>();
    }

    ~BSTreeDict()
    {
        delete tree;
    }

    friend ostream &operator<<(ostream &out, const BSTreeDict<V> &bs)
    {
        out << *(bs.tree) << endl;
        return out;
    }

    V operator[](string key)
    {
        return search(key);
    }

    void insert(string key, V value) override
    {
        TableEntry<V> aux(key, value);
        tree->insert(aux);
    }

    V search(string key) override
    {
        TableEntry<V> aux = TableEntry<V>(key);
        return tree->search(aux).value;
    }

    V remove(string key) override
    {
        TableEntry<V> aux(key);
        V pos = search(key);
        tree->remove(aux);
        return pos;
    }

    int entries() override
    {
        return tree->size();
    }
};

#endif