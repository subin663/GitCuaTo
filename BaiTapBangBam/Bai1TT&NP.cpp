#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1; 
}
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;  // Không tìm th?y
}


int main() {
    int arr[] = {5, 3, 7, 2, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    //int index = sequentialSearch(arr, size, target);
    int index = binarySearch(arr, size, target);
    if (index != -1)
        cout << "Phan tu " << target << " o vi tri: " << index << endl;
    else
        cout << "Khong tim thay phan tu." << endl;
    return 0;
}

