#include <iostream>


template <typename T>
class IComparer {
    public:
        int compareTo(T obj) = 0;
}