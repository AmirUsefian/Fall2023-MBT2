#include <iostream>

class SelectionSort {
public:
    static void sort(int* arr, int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(&arr[minIndex], &arr[i]);
        }
    }

private:
    static void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    SelectionSort::sort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}