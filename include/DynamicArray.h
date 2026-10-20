#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <new>
#include <type_traits>
#include <cmath>
#include <typeinfo>

template <typename T>
class DynamicArray {
private:
    T* data_;
    size_t size_;

    void validateIndex(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Ошибка: Индекс выходит за пределы массива!");
        }
    }

    void validateValue(const T& value) const {
        if constexpr (std::is_integral_v<T>) {
            if (value < -100 || value > 100) {
                throw std::invalid_argument("Ошибка: Значение вне допустимого диапазона [-100, 100]!");
            }
        }
    }

public:
    explicit DynamicArray(size_t size) : size_(size) {
        data_ = new T[size_]{};
    }

    ~DynamicArray() {
        delete[] data_;
    }

    DynamicArray(const DynamicArray& other) : size_(other.size_) {
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    size_t getSize() const { return size_; }

    void setElement(size_t index, const T& value) {
        validateIndex(index);
        validateValue(value);
        data_[index] = value;
    }

    T getElement(size_t index) const {
        validateIndex(index);
        return data_[index];
    }

    void pushBack(const T& value) {
        validateValue(value);
        T* newData = new T[size_ + 1];
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
            T otherVal = (i < other.size_) ? other.data_[i] : T{};
            data_[i] += otherVal;
        }
    }

    void subtract(const DynamicArray& other) {
        for (size_t i = 0; i < size_; ++i) {
            T otherVal = (i < other.size_) ? other.data_[i] : T{};
            data_[i] -= otherVal;
        }
    }

    double distance(const DynamicArray& other) const {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        } else {
            if (size_ != other.size_) {
                throw std::invalid_argument("Ошибка: Размеры массивов должны совпадать!");
            }
            double sum = 0.0;
            for (size_t i = 0; i < size_; ++i) {
                double diff = static_cast<double>(data_[i]) - static_cast<double>(other.data_[i]);
                sum += diff * diff;
            }
            return std::sqrt(sum);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
        os << "[ ";
        for (size_t i = 0; i < arr.size_; ++i) {
            os << arr.data_[i] << " ";
        }
        os << "]";
        return os;
    }
};

#endif
