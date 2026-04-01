#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <memory>

template <class T>
class genericIterator {
    
    public: 
        genericIterator() noexcept {}
        genericIterator(T* ptr) noexcept : ptr(ptr) {}

        T& operator * () const noexcept {
            return *ptr;
        }

        genericIterator& operator ++ () noexcept {
            ++ptr;
            return *this;
        }

        genericIterator& operator -- () noexcept {
            --ptr;
            return *this;
        }

        std::ptrdiff_t operator - (const genericIterator& other) const noexcept {
            return std::distance(this->ptr, other.ptr);
        }

        bool operator == (const genericIterator& other) const noexcept {
            return (other - *this) == 0;
        }

        bool operator != (const genericIterator& other) const noexcept {
            return !(*this == other);
        }

        bool operator < (const genericIterator& other) const noexcept {
            return 0 < (*this - other);
        }

        bool operator > (const genericIterator& other) const noexcept {
            return 0 > (*this - other);
        }

        bool operator <= (const genericIterator& other) const noexcept {
            return !(*this > other);
        }

        bool operator >= (const genericIterator& other) const noexcept {
            return !(*this < other);
        }

    private:
        T* ptr = nullptr;
        
};


template <class T> 
class myVector {
    
    size_t s_ = 0;
    size_t c_ = 2;
    
    std::unique_ptr<T[]> data_ = std::make_unique<T[]> (2);

    
    public: 
        // Aliases
        // using iterator = genericIterator<T>;
        
        // Constructors
        myVector() noexcept {}

        myVector(const myVector& other) noexcept : s_(other.s_), c_(other.c_) {
            data_.reset(new T[other.c_]);
            
            for (size_t i = 0; i < other.s_; i++) {
                data_[i] = other.data_[i];
            }
        }
        
        myVector(size_t size, T val) noexcept : s_(size), c_(size * 2), data_(std::make_unique<T[]>(size)) 
        {
            for (size_t i = 0; i < size; i++) {
                data_[i] = val;
            }
        }

        // Destructor
        ~myVector() = default;

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

            return data_[pos];
        }

        T operator [] (size_t idx) {
            return data_[idx];
        }

        inline T front () { return this->data_[0]; }

        inline T back () { return this->data_[s_]; }

        ////////////////////////////////////////////////////////////////////////////

        // Capacity
        inline bool empty() { return this->s_ == 0; }
        
        inline size_t size() { return this->s_; }
        
        inline size_t length() { return this->s_; }
        
        inline size_t max_size() { return std::numeric_limits<size_t>::max(); }

        constexpr inline void reserve(size_t new_cap) {
            if (new_cap > this->max_size()) throw std::length_error("New cap is higher than max_size");
            
            if (new_cap <= c_) return;

            std::unique_ptr<T[]> newData = std::make_unique<T[]> (new_cap);
            
            for (size_t i = 0; i < this->size(); i++) {
                newData[i] = data_[i];
            }

            data_.swap(newData);

            c_ = new_cap;
        }

        inline size_t capacity() { return this->c_; }

        void shrink_to_fit() { 
            // TO BE IMPLEMENTED
        }

        ////////////////////////////////////////////////////////////////////////////

        constexpr inline void clear() noexcept {
            data_.reset(new T[c_]);
            
            s_ = 0;
        }

        void insert(T* pos, const T& value) {
            if (s_ == (c_-1)) {
                this->extendArr();
            }

            for (size_t i = s_; i >= pos; i--) {
                data_[i+1] = data_[i]; 
            }

            data_[pos] = value;
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

        void erase(size_t pos) {
            
        }

        void erase(size_t first, size_t last) {

        }

        // Modifiers
        void push_back(T val) {
            if (s_ == (c_-1)) {
                this->extendArr();
            }

            data_[s_] = val;
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
            
            data_[s_-1] = T();

            s_--;
        }

        constexpr inline void resize(const size_t count) {
            if (count > this->max_size()) throw std::length_error("New cap is higher than max_size");

            if (count == s_) return;

            for (size_t i = s_; i > count; i--) {
                data_[i-1] = T();
            }

            s_ = count;
        }

        constexpr inline void resize(const size_t count, const T& value) {
            if (count <= s_) return resize(count);

            if (count > c_) reserve(count + sqrt(count));

            for (size_t i = s_; i < count; i++) {
                data_[i] = value;
                s_++;
            }
        }

        constexpr inline void swap(myVector& other) {
            myVector copy = other;
            
            other.data_ = this->data_;
            other.s_ = this->s_;
            other.c_ = this->c_;

            this->data_ = copy.data_;
            this->s_ = copy.s_;
            this->c_ = copy.c_;
        }


        //template <typename... Types>
        //myVector& operator = (Types... values) {
        //    return myVector(values...);
        //}

        ////////////////////////////////////////////////////////////////////////////

        // Iterators

        constexpr inline T* begin() noexcept {
            return data_.get();
        }

        constexpr inline T* end() noexcept {
            return data_.get() + s_;
        }

    private:

        // Helpers
        void extendArr() {
            std::unique_ptr<T[]> newData = std::make_unique<T[]> (c_*2);
            
            for (size_t i = 0; i < c_; i++) {
                newData[i] = data_[i];
            }

            data_.swap(newData);

            c_ *= 2;       
        }


};



#endif