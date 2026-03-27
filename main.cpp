#include <iostream>
#include "./myVector/myVector.hpp"

int main () {

    myVect::myVector<int> myVect;
    myVect::myVector<int> myVect2 (2, 3);
    myVect::myVector<int> myVect3 = {1, 2, 3, 4};

    for (int i = 0; i < static_cast<int>(myVect.size()); i++) {
        std::cout << myVect2[i] << " "; 
    }

    /*
    int sum = 0;
    for (int i = 0; i < static_cast<int>(myVect.size()); i++) {
        sum = myVect[i] + sum;
    }

    int sum2 = 0;
    for (int i = 0; i < static_cast<int>(myVect.size()); i++) {
        sum2 = sum2 + myVect2[i];
    }

    int sum3 = 0;
    for (int i = 0; i < static_cast<int>(myVect.size()); i++) {
        sum2 = sum2 + myVect3[i];
    }
    */

    return 0;
}