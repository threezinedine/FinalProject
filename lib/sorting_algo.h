#pragma once
#include <iostream>
#include <string>
#include "i_comparer.h"


template <class T>
void swrap(T &num1, T &num2);


template <typename T>
void bubbleSort(T *arr, int size, bool ascendingOrder, IComparer<T>* compare);