#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include "Movie.hpp"
#include "DynamicArray.hpp"

template<typename DynamicArray>
long long binary_search(int targetYear, const DynamicArray& data,
    unsigned long long low, unsigned long long high) 
{

    if (low > high) {
        return -1;
    }

    unsigned long long mid = low + (high - low) / 2;

    if (data[mid].getYear() == targetYear) {
        return mid;
    }
    else if (data[mid].getYear() < targetYear) {
        return binary_search(targetYear, data, mid + 1, high);
    }
    else {
        return binary_search(targetYear, data, low, mid - 1);
    }
}


#endif