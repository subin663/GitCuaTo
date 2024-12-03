#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

#define MAX_WORDS 100 

int main() {
    fstream fs;
    fs.open("fileinb3.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Khong the mo file!" << endl;
        return 1;
    }

    string line;
    string words[MAX_WORDS];
    int wordCount = 0;

    while (getline(fs, line)) {
        stringstream ss(line);
        string word;

        while (ss >> word) {
            if (wordCount < MAX_WORDS) {
                words[wordCount++] = word;
            }
        }
    }
    fs.close();
    sort(words, words + wordCount);

    cout << "Cac tu sau khi sap xep: ";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}

