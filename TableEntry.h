#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    // Constructor clave + valor
    TableEntry(std::string key, V value) {
        this->key = key;
        this->value = value;
    }

    // Constructor solo clave
    TableEntry(std::string key) {
        this->key = key;
    }

    // Constructor por defecto
    TableEntry() {
        this->key = "";
    }

    // Operador ==
    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        if (te1.key == te2.key) {
            return true;
        } else {
            return false;
        }
    }

    // Operador !=
    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        if (te1.key != te2.key) {
            return true;
        } else {
            return false;
        }
    }

    // Operador << para imprimir ('key' => value)
    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
        out << "('" << te.key << "' => " << te.value << ")";
        return out;
    }

    // Operador < para comparar las claves
    friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2) {
       return ( te1.key < te2.key) ;
    }

    // Operador > para comparar las claves
    friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return ( te1.key > te2.key) ;
    }

};      
 
#endif
