#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <iostream>
#define ARRAY_SIZE 10

template <typename T>
class ArrayManager {
private:
    int length = 0;
    T* elements = nullptr;

public:
    ArrayManager();
    explicit ArrayManager(T* inputArray);
    ~ArrayManager();

    void display() const;
    T findMinimum() const;
};

#include "array_manager.cpp"

#endif
