#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstdint>

namespace myVect {

template <typename T> class myVector {
    
    T arr[2];
    
    uint32_t size = 0;
    uint32_t capacity = 2;
    // buffer missing
    
    public: 
        // Constructors
        myVector() {}

        myVector(int size, T val) {
            
        }

        // Methods
        void push_back(T val);

    private:
        void extendArr(); 
};

}



#endif