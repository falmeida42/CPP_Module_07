
#include "iter.hpp"

template<typename T>
void    printArray(T  *array, size_t len) {
    std::cout << "[" << array[0];
    for (size_t i = 1; i < len; i++)
        std::cout << ", " << array[i];
    std::cout << "]" << std::endl;
}

void    f1(int& i) {
    i++;
}

void    f2(char& c) {
    if (c >= 'a' && c <= 'z')
        c -= 'a' - 'A';
}

void    f3(bool& b) {
    b = (b == true) ? false : true;
}

template<typename T>
void    f4(T& t) {
    t += 42;
}

int main()
{
    int  intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = "String";
    bool boolArray[] = {1, 0, 1, 1};

    std::cout << "Initial values intArray:\n";
    printArray(intArray, 5);
    iter(intArray, 5, &f1);
    printArray(intArray, 5);
    std::cout << "Initial values charArray:\n";
    printArray(charArray, 6);
    iter(charArray, 7, f2);
    printArray(charArray, 6);
    std::cout << "Initial values boolArray:\n";
    printArray(boolArray, 4);
    iter(boolArray, 4, f3);
    printArray(boolArray, 4);

    iter(intArray, 5, f4);
    iter(charArray, 6, f4);
    printArray(intArray, 5);
    printArray(charArray, 6);
}