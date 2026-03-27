#include <iostream>
#include "./myVector/myVector.hpp"

int main () {

    myVector<int> myVect;
    myVector<int> myVect2 (2, 3);
    //myVector<int> myVect3 = {1, 2, 3, 4};

    myVect.reserve(8);
    std::cout << myVect.size() << " " << myVect.capacity() << std::endl;

    myVect2.push_back(4);
    myVect2.push_back(6);
    myVect2.push_back(8);

    for (size_t i = 0; i < myVect2.size(); i++) {
        std::cout << myVect2[i] << " "; 
    }
    std::cout << std::endl;




    //for (size_t i = 0; i < myVect3.size(); i++) {
    //    std::cout << myVect3[i] << " "; 
    //}
    //std::cout << std::endl;

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