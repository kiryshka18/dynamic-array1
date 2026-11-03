#include "DynamicArray.h"
#include <iostream>
#include <utility>

void processArray(DynamicArray<int> arr) {
    std::cout << "  [Внутри функции] arr: " << arr << std::endl;
}

int main() {
    std::cout << "=== Часть 5. Правило пяти ===" << std::endl;

    std::cout << "\n--- Move-конструктор ---" << std::endl;
    DynamicArray<int> arr1(3);
    arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
    std::cout << "arr1 до move: " << arr1 << std::endl;
    
    DynamicArray<int> arr2 = std::move(arr1);
    std::cout << "arr1 после move: " << arr1 << std::endl;
    std::cout << "arr2 (принял данные): " << arr2 << std::endl;

    std::cout << "\n--- Оператор присваивания копированием ---" << std::endl;
    DynamicArray<int> arr3(2);
    arr3[0] = 1; arr3[1] = 2;
    arr2 = arr3;
    std::cout << "arr2 после копирования из arr3: " << arr2 << std::endl;

    std::cout << "\n--- Move-оператор присваивания ---" << std::endl;
    DynamicArray<int> arr4(2);
    arr4[0] = 99; arr4[1] = 88;
    arr2 = std::move(arr4);
    std::cout << "arr2 после move из arr4: " << arr2 << std::endl;
    std::cout << "arr4 после move: " << arr4 << std::endl;

    std::cout << "\n--- Передача по значению ---" << std::endl;
    DynamicArray<int> arr5(3);
    arr5[0] = 7; arr5[1] = 8; arr5[2] = 9;
    
    std::cout << "Вызов processArray(arr5):" << std::endl;
    processArray(arr5);
    
    std::cout << "Вызов processArray(std::move(arr5)):" << std::endl;
    processArray(std::move(arr5));

    return 0;
}
