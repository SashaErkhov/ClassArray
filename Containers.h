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
            return mid; // ������� ������
        }
        else if (*mid < value) {
            start = mid + 1;
            length -= half + 1; // ��������� ����� ��� ������ �����
        }
        else {
            length = half; // ��������� ����� ��� ����� �����
        }
    }

    return end; // ������� �� ������, ���������� ����� ���������
}
