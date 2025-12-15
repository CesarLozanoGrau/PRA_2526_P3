#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include <list> // libreria que icluye la clase ListArray

#include "Dict.h"
#include "TableEntry.h"

template <typename V>
class HashTable : public Dict<V> {

private:
    int n;   // número de elementos almacenados
    int max; // número total de cubetas

    // Cada cubeta ahora es una lista STL
    std::list<TableEntry<V>>* table;

    int h(std::string key) {
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % max;
    }

public:

    // Constructor
    HashTable(int size) {
        if (size <= 0)
            throw std::runtime_error("HashTable size must be positive");

        max = size;
        n = 0;
        table = new std::list<TableEntry<V>>[max];
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    int capacity() {
        return max;
    }

    int entries() override {
        return n;
    }

    // ----------------------------------------------------
    // INSERT
    // ----------------------------------------------------
    void insert(std::string key, V value) override {
        int idx = h(key);

        // buscar si ya existe
        for (const auto& elem : table[idx]) {
            if (elem.key == key)
                throw std::runtime_error("Key '" + key + "' already exists!");
        }

        // insertar al principio (o al final, da igual para el test)
        table[idx].push_front(TableEntry<V>(key, value));
        n++;
    }

    // ----------------------------------------------------
    // SEARCH
    // ----------------------------------------------------
    V search(std::string key) override {
        int idx = h(key);

        for (const auto& elem : table[idx]) {
            if (elem.key == key)
                return elem.value;
        }

        throw std::runtime_error("Key '" + key + "' not found!");
    }

    // Operador [] simplemente usa search()
    V operator[](std::string key) {
        return search(key);
    }

    // ----------------------------------------------------
    // REMOVE
    // ----------------------------------------------------
    V remove(std::string key) override {
        int idx = h(key);

        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->key == key) {
                V val = it->value;
                table[idx].erase(it);
                n--;
                return val;
            }
        }

        throw std::runtime_error("Key '" + key + "' not found!");
    }

    // ----------------------------------------------------
    // OPERADOR <<
    // ----------------------------------------------------
    friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
        out << "HashTable [entries: " << th.n
            << ", capacity: " << th.max << "]\n";
        out << "==============\n\n";

        for (int i = 0; i < th.max; i++) {
            out << "== Cubeta " << i << " ==\n\n";

            out << "List => [\n";
            for (const auto& elem : th.table[i]) {
                out << "  ('" << elem.key << "' => " << elem.value << ")\n";
            }
            out << "]\n\n";
        }

        out << "==============\n";
        return out;
    }

};

#endif

