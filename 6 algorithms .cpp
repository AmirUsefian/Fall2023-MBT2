#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortingAlgorithms {
public:
    vector<int> bubbleSort(vector<int> arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        return arr;
    }

    vector<int> insertionSort(vector<int> arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
        return arr;
    }
    vector<int> selectionSort(vector<int> arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            int minIndex = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
        return arr;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot+1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return i+1;
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    vector<int> heapSort(vector<int> arr) {
        int n = arr.size();

        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }

        return arr;
    }
};

int main() {
    SortingAlgorithms sa;
    vector<int> inputArr = {64, 25, 12, 22, 11, 4, 3, 2, 6, 5, 9, 75};
    vector<int> sortedArr;

    cout << "Choose a sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Heap Sort\n";
   
    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            sortedArr = sa.bubbleSort(inputArr);
            break;
        case 2:
            sortedArr = sa.insertionSort(inputArr);
            break;
        case 3:
            sortedArr = sa.selectionSort(inputArr);
            break;
        case 4:
            sa.quickSort(inputArr, 0, inputArr.size()-1);
            sortedArr = inputArr;
            break;
        case 5:
            sa.mergeSort(inputArr, 0, inputArr.size()-1);
            sortedArr = inputArr;
            break;
        case 6:
            sortedArr = sa.heapSort(inputArr);
            break;
        default:
            cout << "Invalid choice\n";
    }

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}