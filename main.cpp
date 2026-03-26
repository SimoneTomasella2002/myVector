#include <iostream>
#include "./myVector/myVector.hpp"

int main () {

    myVect::myVector<int> myVect;
    //myVector<int> myVect2 = {1, 2, 3, 4};

    for (int i = 0; i < myVect.size; i++) {
        std::cout << myVect[i] << " ";
    }

    return 0;
}