#pragma once

#include <iostream>
using namespace std;

template <class T> class DynamicArray {
private:
    T * _ptr;
    int _size;
    int _capacity;
public:
    // constructor
    DynamicArray() : _size(0), _capacity(1) {
        _ptr = new T[_capacity];
    };
    explicit DynamicArray(const int& size) : _size(size), _capacity(size) {
        _ptr = new T[_capacity];
    };
    // destructor
    ~DynamicArray() {
        delete[] _ptr;
    };
    // getter
    int size() {
        return _size;
    }

    // operation
    void resize(const int &capacity) {
        T* newPtr = new T[capacity];
        for (int i = 0; i < _size; i++) {
            *(newPtr + i) = *(_ptr + i);
        }
        _capacity = capacity;
        delete[] _ptr;
        _ptr = newPtr;
    }

    void push(const T &data) {
        if (_size >= _capacity) {
            resize(_capacity + 1);
        }
        _ptr[_size++] = data;
    }

    void pop() {
        if (0 == this->size) {
            cout << "Empty array." << endl;
            return;
        }
        this->_size--;
    }

    T at(const int &index) {
        if (index < 0 || index >= _size) {
            throw out_of_range("Index out of range.");
        }
        return _ptr[index];
    }

    T operator[] (const int &index) {
        if (index < 0 || index >= _size) {
            throw out_of_range("Index out of range.");
        }
        return _ptr[index];
    }
};