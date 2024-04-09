#pragma once
#include "Array.h"

template <typename T>
typename Array<T>::iterator binarySearch(T value, typename Array<T>::iterator begin, typename Array<T>::iterator end) {
    auto start = begin;
    auto length = end - begin; 

    while (length > 0) {
        auto half = length / 2;
        auto mid = start + half;

        if (*mid == value) {
            return mid; // Ёлемент найден
        }
        else if (*mid < value) {
            start = mid + 1;
            length -= half + 1; // ќбновл€ем длину дл€ правой части
        }
        else {
            length = half; // ќбновл€ем длину дл€ левой части
        }
    }

    return end; // Ёлемент не найден, возвращаем конец диапазона
}
