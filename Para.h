//
// Created by sasor on 16.04.2024.
//

#ifndef TESTS_PARA_H
#define TESTS_PARA_H

#include <iostream>

template <typename T, typename U>
class Para
{
public:
    T first;
    U second;
    Para(T f = T(), U s = U()) : first(f), second(s) {}
    Para(const Para& p) : first(p.first), second(p.second) {}
    Para(Para&& p) : first(std::move(p.first)), second(std::move(p.second)) {}
    Para& operator=(const Para& p)
    {
        first = p.first;
        second = p.second;
        return *this;
    }
    Para& operator=(Para&& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }
    static void swap(Para& p1, Para& p2)
    {
        std::swap(p1.first, p2.first);
        std::swap(p1.second, p2.second);
    }

    bool operator==(const Para& rhs) const
    {
        return this->first == rhs.first;
    }

    bool operator<(const Para& rhs) const
    {
        return this->first < rhs.first;
    }

    bool operator!=(const Para& rhs) const
    {
        return !(*this == rhs);
    }

    bool operator>(const Para& rhs) const
    {
        return rhs < *this;
    }

    bool operator<=(const Para& rhs) const
    {
        return !(*this > rhs);
    }

    bool operator>=(const Para& rhs) const
    {
        return !(*this < rhs);
    }
};

#endif //TESTS_PARA_H
