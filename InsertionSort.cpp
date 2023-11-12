#include <iostream>
using namespace std;
class InsertionSort {
    private :
        int*arr;
        int size;

        public:
        InsertionSort(int*array, int length){
            arr = new int[length];
            size = length;
            for(int i = 0;i<length;i++){
                arr[i] = array[i];
            }
        }
        ~InsertionSort(){
            delete[]arr;
        }
        void sort(){
            int i, key, j;
            for(int i = 0;i<size;i++){
                key = arr[i];
                j = i-1;
            
            while(j>=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
            }
        }
        void printArray(){
            for(int i = 0;i<size;i++){
            cout<<arr[i]<<""<<endl;
            }
        }
};

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int length = sizeof(arr)/sizeof(arr[0]);

    InsertionSort insertionSort(arr, length);
    insertionSort.sort();
    cout<<"Sorted Array:";
    insertionSort.printArray();
    return 0;
}
