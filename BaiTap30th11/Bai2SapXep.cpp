#include <iostream>
#include <fstream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionMinMax(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partitionMaxMin(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSortMinMax(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionMinMax(arr, low, high);
        quickSortMinMax(arr, low, pi - 1);
        quickSortMinMax(arr, pi + 1, high);
    }
}

void quickSortMaxMin(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionMaxMin(arr, low, high);
        quickSortMaxMin(arr, low, pi - 1);
        quickSortMaxMin(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;    
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Neu goc khong phai lon nhat
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // De quy heapify cho node bi thay doi
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Xay dung heap (dong)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
void heapifyMaxToMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMaxToMin(arr, n, smallest);
    }
}

void heapSortMaxToMin(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMaxToMin(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMaxToMin(arr, i, 0);
    }
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // S? ph?n t? bên trái
    int n2 = r - m;     // S? ph?n t? bên ph?i

    int L[n1], R[n2];   // T?o m?ng t?m

    // Sao chép d? li?u vào m?ng t?m
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    // G?p m?ng
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép ph?n t? còn l?i
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ð? quy s?p x?p hai n?a
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // H?p nh?t hai n?a dã s?p x?p
        merge(arr, l, m, r);
    }
}
void naturalMergeSort(int arr[], int n) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;

        int i = 0;

        // Duy?t qua t?t c? các chu?i tang d?n
        while (i < n - 1) {
            int start = i;

            // Tìm chu?i tang d?n
            while (i < n - 1 && arr[i] <= arr[i + 1]) {
                i++;
            }
            int mid = i;

            // Tìm chu?i ti?p theo
            while (i < n - 1 && arr[i] > arr[i + 1]) {
                i++;
            }
            int end = i;

            if (end > start) {
                merge(arr, start, mid, end);
                sorted = false;
            }

            i++;
        }
    }
}



int main(){
	fstream fs;
	fs.open("filein.txt");
	if (fs.is_open()){
		cout<<"Mo file thanh cong";
		cout<<endl;
	}
	    
    int arr[100], n = 0;
    while (fs >> arr[n]) { 
        n++;
    }

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    //heapSort(arr, n);
    //heapSortMaxToMin(arr, n);
    //quickSortMinMax(arr, 0, n - 1);
    //mergeSort(arr, 0, n - 1);

	cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

	return 0;
}






