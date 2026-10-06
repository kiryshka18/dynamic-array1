#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>

int main() {
    std::cout << "=== Демонстрация исключений (Часть 2) ===" << std::endl;

    try {
        DynamicArray arr(2);
        arr.setElement(5, 10);
    } catch (const std::out_of_range& e) {
        std::cout << "Перехвачено (out_of_range): " << e.what() << std::endl;
    }

    try {
        DynamicArray arr(2);
        arr.setElement(0, 150);
    } catch (const std::invalid_argument& e) {
        std::cout << "Перехвачено (invalid_argument): " << e.what() << std::endl;
    }

    try {
        size_t hugeSize = static_cast<size_t>(-1);
        DynamicArray giantArr(hugeSize);
    } catch (const std::bad_alloc& e) {
        std::cout << "Перехвачено (bad_alloc): Память не выделена (" << e.what() << ")" << std::endl;
    }

    return 0;
}
