#include <iostream>
#include <list>
using namespace std;

class HashTable {
public:
    list<int>* table;
    int size;

    HashTable(int n) {
        size = n;
        table = new list<int>[size];
    }

    void insert(int key) {
        int index = key % size;
        table[index].push_back(key);  // Thêm ph?n t? vào danh sách liên k?t
    }

    bool search(int key) {
        int index = key % size;
        for (int x : table[index]) {
            if (x == key) return true;
        }
        return false;  // Không tìm th?y
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (!table[i].empty()) {
                cout << "table[" << i << "] = ";
                for (int x : table[i]) {
                    cout << x << " ";
                }
                cout << endl;
            }
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

