#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <cmath>

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
        
        ////////////////////////////////////////////////////////////////////////////
        
        // Element Access 
        T at(int pos) {
            if (pos >= s_) throw std::out_of_range("Out of range exception!");

            return arr[pos];
        }

        T operator [] (size_t idx) {
            return arr[idx];
        }

        inline T front () { return this->arr[0]; }

        inline T back () { return this->arr[s_]; }

        ////////////////////////////////////////////////////////////////////////////

        // Capacity
        inline bool empty() { return this->s_ == 0; }
        
        inline size_t size() { return this->s_; }
        
        inline size_t length() { return this->s_; }
        
        inline size_t max_size() { return std::numeric_limits<size_t>::max(); }

        void reserve(size_t new_cap) {
            if (new_cap > this->max_size()) throw std::length_error("New cap is higher than max_size");
            
            if (new_cap < c_) return;

            T* newArr = new T[new_cap];
            
            for (size_t i = 0; i < this->size(); i++) {
                newArr[i] = arr[i];
            }

            delete arr;

            arr = newArr;
            c_ = new_cap;
        }

        inline size_t capacity() { return this->c_; }

        void shrink_to_fit() { 
            // TO BE IMPLEMENTED
        }

        ////////////////////////////////////////////////////////////////////////////

        void clear() {
            delete arr;
            s_ = 0;
            
            arr = new T[c_];
        }

        void insert(size_t pos, const T& value) {
            if (s_ == (c_-1)) {
                this->extendArr();
            }

            for (size_t i = s_; i >= pos; i--) {
                arr[i+1] = arr[i]; 
            }

            arr[pos] = value;
            s_++;
        }

        void insert(size_t pos, uint32_t count, const T& value) {
            // TO BE IMPLEMENTED
        }

        void insert_range() {
            // TO BE IMPLEMENTED
        }

        void emplace() {
            // TO BE IMPLEMENTED
        }

        void erase() {
            // TO BE IMPLEMENTED
        }

        // Modifiers
        void push_back(T val) {
            if (s_ == (c_-1)) {
                this->extendArr();
            }

            arr[s_] = val;
            s_++;
        }

        void emplace_back() {
            // TO BE IMPLEMENTED
        }

        void append_range() {
            // TO BE IMPLEMENTED
        }

        constexpr inline void pop_back() {
            if (s_ == 0) return;
            
            arr[s_-1] = T();

            s_--;
        }

        constexpr void resize(const size_t count) {
            if (count > this->max_size()) throw std::length_error("New cap is higher than max_size");

            if (count == s_) return;

            for (size_t i = s_; i > count; i--) {
                arr[i-1] = T();
            }

            s_ = count;
        }

        constexpr void resize(const size_t count, const T& value) {
            if (count <= s_) return resize(count);

            if (count > c_) reserve(count + sqrt(count));

            for (size_t i = s_; i < count; i++) {
                arr[i] = value;
                s_++;
            }
        }

        void swap(myVector& other) {
            myVector copy = other;
            
            other.arr = this->arr;
            other.s_ = this->s_;
            other.c_ = this->c_;

            this->arr = copy.arr;
            this->s_ = copy.s_;
            this->c_ = copy.c_;
        }


        //template <typename... Types>
        //myVector& operator = (Types... values) {
        //    return myVector(values...);
        //}
        
    private:

        // Helpers
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