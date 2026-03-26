#include "myVector.hpp"

namespace myVect {

    template <typename T> 
    void myVector<T>::push_back(T val) { 
        if (size == (capacity-1)) {
            extendArr();
        }

        arr[size] = val;
        size++;
    }

    template <typename T>
    void myVector<T>::extendArr() {
        T* newArr = new T[capacity*2];

        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }

        delete arr;
        arr = newArr;
        capacity *= 2;
    }
}

