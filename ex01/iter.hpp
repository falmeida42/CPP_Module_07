#ifndef ITER_H
#define ITER_H

#include <iostream>
#include <stdlib.h>

template <typename T>
void    iter(T *array, size_t length, void (*f)(T& element)) {

    for (int i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif