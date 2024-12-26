#ifndef ARRAY_MANAGER_CPP
#define ARRAY_MANAGER_CPP

#include "array_manager.h"

template <typename T>
ArrayManager<T>::ArrayManager() {}

template <typename T>
ArrayManager<T>::ArrayManager(T* inputArray) : length(ARRAY_SIZE), elements(new T[ARRAY_SIZE]) {
    for (int i = 0; i < length; ++i) {
        elements[i] = inputArray[i];
    }
}

template <typename T>
ArrayManager<T>::~ArrayManager() {
    delete[] elements;
}

template <typename T>
void ArrayManager<T>::display() const {
    for (int i = 0; i < length; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T ArrayManager<T>::findMinimum() const {
    if (length == 0) {
        throw std::runtime_error("Array is empty.");
    }

    T minElement = elements[0];
    for (int i = 1; i < length; ++i) {
        if (elements[i] < minElement) {
            minElement = elements[i];
        }
    }

    return minElement;
}

#endif
