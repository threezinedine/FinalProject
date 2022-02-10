#include <iostream>
#include <sorting_algo.h>

template <class T>
void swrap(T &num1, T &num2) {
    T* temp = num1;
    num1 = num2;
    num2 = temp;
}

template <typename T>
void bubbleSort(T *arr, int size, bool ascendingOrder, IComparer<T>* compare) {
    int swrapNum;
    int i, j;

    if (ascendingOrder) {
        swrapNum = 1;
    }
    else {
        swrapNum = -1;
    }

    for (i=0; i<size-1; i++) {
        for (j=i+1;j<size;j++){
            if (compare->compareTo(arr[i], arr[j]) == swrapNum){
                swrap<T>(&arr[i], &arr[j]);
            }
        }
    }
}