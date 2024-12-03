#include <iostream>
using namespace std;

class HashTable {
public:
    int* table;
    int size;

    HashTable(int n) {
        size = n;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int index = key % size;
        table[index] = key;
    }

    bool search(int key) {
        int index = key % size;
        return table[index] == key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1)
                cout << "table[" << i << "] = " << table[i] << endl;
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.display();

    cout << "Tim 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Tim 10: " << (ht.search(10) ? "Found" : "Not Found") << endl;

    return 0;
}

