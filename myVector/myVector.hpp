#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstdint>
#include <stdexcept>

namespace myVect {

template <typename T> class myVector {
    
    uint32_t s = 0;
    uint32_t c = 2;
    
    T* arr = new T[2];

    
    public: 
        // Parameters
        
        // Constructors
        myVector() {}
        
        myVector(int size, T val) {
            T* newArr = new T[size];
            
            for (int i = 0; i < size; i++) {
                newArr[i] = val;
            }
            
            delete arr;
            arr = newArr;
        }

        template <typename... Types>
        myVector(T value, Types... values) {
            this->push_back(value);

            myVector(values...);
        }
        
        // Methods
        void push_back(T val);
        T at(int pos);
        uint32_t size();
        uint32_t length();
        uint32_t capacity();
        bool empty();

        // Operator Overload
        myVector operator [] (int idx) {
            return arr[idx];
        }

        template <typename... Types>
        myVector operator = (Types... values) {
            return myVector(values...);
        }

        friend std::ostream & operator << ( std::ostream &os, const myVector<T> &vect) {
            
        }
        
    private:
        void extendArr(); 
};

}



#endif