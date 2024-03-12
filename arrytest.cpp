#include "Arry.h"
#include <iostream>
void testsGetElements(){

}
void testsAddElements() {
    Arry<int> arr1(5);
    arr1.addElement(10);
    std::cout << "test1: " << std::endl;
    if (arr1.getElement(0) != 10) {
        std::cout << "Add one element: " << "failed" << std::endl;
    } else {
        std::cout << "Add one element: " << "passed" << std::endl;
    }
    Arry<int> arr2(5);
    arr2.addElement(0);
    arr2.addElement(30);
    std::cout << "test2: " << std::endl;
    if (arr2.getElement(0) != 0 && arr2.getElement(1) != 30) {
        std::cout << "Add two element: " << "failed" << std::endl;
    } else{
        std::cout << "Add two element: " << "passed" << std::endl;
    }
    Arry<int> arr3(2);
    arr3.addElement(0);
    arr3.addElement(1);
    arr3.addElement(3);
    std::cout << "test3: " << std::endl;
    if (arr3.getElement(0) != 0 && arr3.getElement(1) != 1 && arr3.getElement(2) != 3) {
        std::cout << "Add more then capaticity: " << "failed" << std::endl;
    } else{
        std::cout << "Add more then capaticity: " << "passed" << std::endl;
    }
    Arry<int> arr4;
    for (int i = 0; i < 1000; ++i){
        arr4.addElement(i);
    }
    bool passed = true;
    std::cout << "test4: " << std::endl;
    for (int i = 0; i < 1000; ++i){
        if (arr3.getElement(i) != i) {
            std::cout << "Big count of data: " << "failed" << std::endl;
            passed = false;
            break;
        }
    }
    if (passed) {
        std::cout << "Big count of data: " << "passed" << std::endl;
    }
}

void testsResizeArray() {
    //TODO do tests for resize
}

void testsRemoveElements() {
    Arry<int> arr1(5);
    arr1.addElement(10);
    arr1.addElement(110);
    arr1.removeElement(0);
    std::cout << "test1: " << std::endl;
    if (arr1.getElement(0) == 110) {
        std::cout << "Remove one element from start: " << "passed" << std::endl;
    } else {
        std::cout << "Remove one element from start: " << "failed" << std::endl;
    }

    Arry<int> arr2(5);
    arr2.addElement(0);
    arr2.addElement(30);
    arr2.removeElement(1);
    std::cout << "test2: " << std::endl;
    if (arr2.getElement(0) == 0) {
        std::cout << "Remove last element: " << "passed" << std::endl;
    } else {
        std::cout << "Remove last element: " << "failed" << std::endl;
    }

    Arry<int> arr3(5);
    arr3.addElement(0);
    arr3.addElement(1);
    arr3.addElement(3);
    arr3.removeElement(1);
    std::cout << "test3: " << std::endl;
    if (arr3.getElement(1) == 3) {
        std::cout << "Remove one element from middle: " << "passed" << std::endl;
    } else {
        std::cout << "Remove one element from middle: " << "failed" << std::endl;
    }

    Arry<int> arr4;
    for (int i = 0; i < 1000; ++i){
        arr4.addElement(i);
    }
    arr4.removeElement(500);
    std::cout << "test4: " << std::endl;
    if (arr4.getElement(998) == 999 && arr4.getElement(500) == 501) {
        std::cout << "Remove element from big data: " << "passed" << std::endl;
    } else {
        std::cout << "Remove element from big data: " << "failed" << std::endl;
    }
}

void testsSetElement() {
    //TODO do tests for set function
}
void runTest() {
    std::cout << "--------------addElement-----------------" << std::endl;
    testsAddElements();
    std::cout << "--------------removeElement-----------------" << std::endl;
    testsRemoveElements();
}

int main() {
    runTest();
    return 0;
}