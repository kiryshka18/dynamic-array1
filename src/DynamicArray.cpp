#include "DynamicArray.h"
#include <new>

void DynamicArray::validateIndex(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Ошибка: Индекс выходит за пределы массива!");
    }
}

void DynamicArray::validateValue(int value) const {
    if (value < -100 || value > 100) {
        throw std::invalid_argument("Ошибка: Значение вне допустимого диапазона [-100, 100]!");
    }
}

DynamicArray::DynamicArray(size_t size) : size_(size) {
    data_ = new int[size_]{}; 
}

DynamicArray::~DynamicArray() {
    delete[] data_;
}

DynamicArray::DynamicArray(const DynamicArray& other) : size_(other.size_) {
    data_ = new int[size_]; 
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

size_t DynamicArray::getSize() const {
    return size_;
}

void DynamicArray::print() const {
    std::cout << "[ ";
    for (size_t i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void DynamicArray::setElement(size_t index, int value) {
    validateIndex(index);
    validateValue(value);
    data_[index] = value;
}

int DynamicArray::getElement(size_t index) const {
    validateIndex(index);
    return data_[index];
}

void DynamicArray::pushBack(int value) {
    validateValue(value);
    int* newData = new int[size_ + 1]; 
    for (size_t i = 0; i < size_; ++i) {
        newData[i] = data_[i];
    }
    newData[size_] = value;
    delete[] data_;
    data_ = newData;
    size_++;
}

void DynamicArray::add(const DynamicArray& other) {
    for (size_t i = 0; i < size_; ++i) {
        int otherVal = (i < other.size_) ? other.data_[i] : 0;
        data_[i] += otherVal;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (size_t i = 0; i < size_; ++i) {
        int otherVal = (i < other.size_) ? other.data_[i] : 0;
        data_[i] -= otherVal;
    }
}
