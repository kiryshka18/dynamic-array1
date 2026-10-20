#include "DynamicArray.h"
#include <iostream>
#include <string>

int main() {

  
    DynamicArray<int> arr1(3);
    arr1.setElement(0, 10);
    arr1.setElement(1, -50);
    arr1.setElement(2, 100);
    std::cout << "arr1: " << arr1 << std::endl;

    try {
        arr1.setElement(0, 200);
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано: " << e.what() << std::endl;
    }

  
    DynamicArray<std::string> strArr(2);
    strArr.setElement(0, "Hello");
    strArr.setElement(1, "World");
    std::cout << "strArr: " << strArr << std::endl;

    std::cout << "\n--- Расстояние ---" << std::endl;
    DynamicArray<int> a(2);
    a.setElement(0, 3); a.setElement(1, 4);
    DynamicArray<int> b(2);
    b.setElement(0, 0); b.setElement(1, 0);
    
    std::cout << "Расстояние a и b: " << a.distance(b)  << std::endl;

    try {
        DynamicArray<int> c(3);
        a.distance(c);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка размера: " << e.what() << std::endl;
    }

    try {
        DynamicArray<std::string> s1(2), s2(2);
        s1.distance(s2);
    } catch (const std::bad_typeid& e) {
        std::cout << "Ошибка типа: std::bad_typeid" << std::endl;
    }

    return 0;
}
