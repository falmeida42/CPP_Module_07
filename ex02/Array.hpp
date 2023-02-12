#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {

    private:
        T       *array;
        size_t  s = 0;

        class   out : public std::exception {
            const char *what() const throw() {
                return "Index out of bounds";
            }
        };

    public:
    Array() { array = new T[0](); }


    Array(const int &i) : array(0), s(i) {

        array = new T[s]();
    }

    Array(const Array& other) {
        if (this != &other) {
            array = new T[other.s]();
            s = other.s;
            for (size_t i = 0; i < other.s; i++) {
                array[i] = other.array[i];
            }
        }
    }

    Array&  operator=(const Array& other) {
        if (this != &other) {
            delete[] array;
            array = new T[other.s]();
            s = other.s;
            for (int i = 0; i < other.s; i++)
                array[i] = other.array[i];
        }
        return *this;
    }

    T&  operator[](int i) const {
        
        if (i < 0 || size_t(i) >= s)
            throw out();

        return array[i];
    }

    size_t  size(void) const { return (s); }

    ~Array() {
        if (array != NULL) {
            delete [] array;
            array = NULL; 
        }
    }
};

#endif