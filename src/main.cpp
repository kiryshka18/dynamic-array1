#include "DynamicArray.h"
#include <iostream>
#include <string>

int main() {

    DynamicArray<int> arr1(3);
    arr1[0] = 10;
    arr1[1] = -20;
    arr1[2] = 30;
    std::cout << "arr1: " << arr1 << std::endl;
    
    try {
        arr1[5] = 10;
    } catch (const std::out_of_range& e) {
        std::cout << "Ошибка индекса: " << e.what() << std::endl;
    }

    DynamicArray<int> arr2(3);
    arr2[0] = 10; arr2[1] = -20; arr2[2] = 30;
    
    DynamicArray<int> arr3(3);
    arr3[0] = 10; arr3[1] = -20; arr3[2] = 99;

    std::cout << "arr1 == arr2: " << (arr1 == arr2) << std::endl;
    std::cout << "arr1 != arr3: " << (arr1 != arr3) << std::endl;

    DynamicArray<int> arr4(2);
    arr4[0] = 5; arr4[1] = -5;
    
    arr1 += arr4;
    std::cout << "arr1 после += arr4: " << arr1 << std::endl;
    
    arr1 -= arr4;
    std::cout << "arr1 после -= arr4: " << arr1 << std::endl;

    arr1 += 10;
    std::cout << "arr1 после += 10: " << arr1 << std::endl;
    
    arr1 -= 20;
    std::cout << "arr1 после -= 20: " << arr1 << std::endl;

    std::cout << "arr1 (через итератор): ";
    for (const auto& x : arr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto& x : arr1) {
        x += 1;
    }
    std::cout << "arr1 после изменения через итератор: " << arr1 << std::endl;

    return 0;
}
