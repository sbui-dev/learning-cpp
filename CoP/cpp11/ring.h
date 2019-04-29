#pragma once
#include <iostream>
using namespace std;

// outer class
template<class T>
class Ring {
private:
    T *m_values;
    int m_size;
    int m_pos;
public:
    // can create a prototype and define the class later
    class iterator;

public:
    Ring(int size) : m_size(size), m_values(NULL), m_pos(0) {
        m_values = new T[size];
    }

    ~Ring() {
        delete [] m_values;
    }
    // return size
    int size() {
        return m_size;
    }

    // add elements and set back to beginning when buffer size is reached
    void add(T value) {
        m_values[m_pos++] = value;
        if (m_pos == m_size) {
            m_pos = 0;
        }
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    // return value at pos
    T &get(int pos) {
        return m_values[pos];
    }
};


// inner class
template<class T>
class Ring<T>::iterator {
private:
    int m_pos;
    Ring &m_ring;
public:
    iterator(int pos, Ring& aRing) : m_ring(aRing), m_pos(pos) {
    }
    void print() {
        cout << "Hello: " << T() << endl;
    }

    // postfix ++; the param indicates postfix instead of prefix
    iterator &operator++(int) {
        m_pos++;
        return *this;
    }

    // prefix ++
    iterator &operator++() {
        m_pos++;
        return *this;
    }

    T& operator*() {
        return m_ring.get(m_pos);
    }

    // check position
    bool operator!=(const iterator &other) const {
        return m_pos != other.m_pos;
    }
};
