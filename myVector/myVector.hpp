#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstdint>
#include <stdexcept>

template <class T> class myVector {
    
    size_t s_ = 0;
    size_t c_ = 2;
    
    T* arr = new T[2];

    
    public: 
        // Parameters
        
        // Constructors

        myVector() {}
        
        myVector(size_t size, T val) {
            s_ = size;
            c_ = size * 2;
            arr = new T[size];

            for (size_t i = 0; i < size; i++) {
                arr[i] = val;
            }
        }

        //template <typename... Types>
        //myVector(T value, Types... values) {
        //    this->push_back(value);
//
        //    myVector(values...);
        //}
        
        
        // Methods
        void push_back(T val) {
            if (s_ == (c_-1)) {
                this->extendArr();
            }

            arr[s_] = val;
            s_++;
        }
        
        T at(int pos) {
            if (pos >= s_) throw std::out_of_range("Out of range exception!");

            return arr[pos];
        }
        
        inline size_t size() { return this->s_; }

        inline size_t length() { return this->s_; }

        inline size_t capacity() { return this->c_; }
        
        bool empty() { return this->s_ == 0; }

        // Operator Overload
        T operator [] (size_t idx) {
            return arr[idx];
        }

        //template <typename... Types>
        //myVector& operator = (Types... values) {
        //    return myVector(values...);
        //}
        
    private:
        void extendArr() {
            T* newArr = new T[c_*2];

            for (size_t i = 0; i < c_; i++) {
                newArr[i] = arr[i];
            }
        
            delete arr;
            arr = newArr;
            c_ *= 2;            
        }


};


#endif