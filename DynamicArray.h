#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data_;
    size_t size_;

    void validateIndex(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Ошибка: Индекс выходит за пределы массива!");
        }
    }

    void validateValue(int value) const {
        if (value < -100 || value > 100) {
            throw std::out_of_range("Ошибка: Значение вне допустимого диапазона [-100, 100]!");
        }
    }

public:
    explicit DynamicArray(size_t size) : size_(size) {
        data_ = new int[size_]{};
    }

    ~DynamicArray() {
        delete[] data_;
    }

    DynamicArray(const DynamicArray& other) : size_(other.size_) {
        data_ = new int[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    size_t getSize() const {
        return size_;
    }

    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size_; ++i) {
            std::cout << data_[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    void setElement(size_t index, int value) {
        validateIndex(index);
        validateValue(value);
        data_[index] = value;
    }

    int getElement(size_t index) const {
        validateIndex(index);
        return data_[index];
    }

    void pushBack(int value) {
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

    void add(const DynamicArray& other) {
        for (size_t i = 0; i < size_; ++i) {
            int otherVal = (i < other.size_) ? other.data_[i] : 0;
            data_[i] += otherVal;
        }
    }

    void subtract(const DynamicArray& other) {
        for (size_t i = 0; i < size_; ++i) {
            int otherVal = (i < other.size_) ? other.data_[i] : 0;
            data_[i] -= otherVal;
        }
    }
};

#endif