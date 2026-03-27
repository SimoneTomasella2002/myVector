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

    template <typename T>
    T myVector<T>::at(int pos) {
        if (pos >= size) throw std::out_of_range("Out of range exception!");

        return arr[pos];
    }

    template <typename T>
    uint32_t myVector<T>::size() {
        return this->s;
    }

    template <typename T>
    uint32_t myVector<T>::length() {
        return this->s;
    }

    template <typename T>
    uint32_t myVector<T>::capacity() {
        return this->c;
    }

    template <typename T>
    bool myVector<T>::empty() {
        return this->size == 0;
    }
}

