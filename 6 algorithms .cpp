#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortingAlgorithms {
public:
    // Bubble Sort
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    // Insertion Sort
    void insertionSort(vector<int>& arr) {
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
    }

    // Selection Sort
    void selectionSort(vector<int>& arr) {
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
    }

    // Quick Sort
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
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
        return i + 1;
    }

    // Heap Sort
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n-1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
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

    // Binary Search
    int binarySearch(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    SortingAlgorithms sortAlgo;
    vector<int> arr;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << "Choose a sorting algorithm: " << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Heap Sort" << endl;

    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            sortAlgo.bubbleSort(arr);
            break;
        case 2:
            sortAlgo.insertionSort(arr);
            break;
        case 3:
            sortAlgo.selectionSort(arr);
            break;
case 4:
            sortAlgo.quickSort(arr, 0, arr.size()-1);
            break;
        case 5:
            sortAlgo.heapSort(arr);
            break;
        default:
            cout << "Invalid choice" << endl;
            return 0;
    }

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Binary Search
    int key = arr[0];
    int index = sortAlgo.binarySearch(arr, key);
    if (index != -1) {
        cout << "Smallest element: " << arr[index] << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}