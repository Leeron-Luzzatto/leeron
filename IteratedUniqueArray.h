#ifndef ITERATED_UNIQUEARRAY_H
#define ITERATED_UNIQUEARRAY_H

#include "UniqueArray.h"
#include <iostream>

const int undefined_iterator = -1;

template <class Element, class Compare = std::equal_to<Element>>
class IteratedUniqueArray: public UniqueArray<Element, Compare> {
    int iterator;

public:
    IteratedUniqueArray(unsigned int size): UniqueArray<Element, Compare>(size), iterator(undefined_iterator){}
    IteratedUniqueArray(const UniqueArray& other){}
    ~IteratedUniqueArray(){}
    IteratedUniqueArray& operator=(const UniqueArray&) = delete{}
    bool remove(const Element& element){}
    Element& getNext(){}
    Element& getFirst(){}

    class Filter {
    public:
        virtual bool operator() (const Element&) const = 0;
    };
    IteratedUniqueArray filter(const Filter& f) const{}
    class IteratedUniqueArrayIsEmptyException{};
};

#endif //ITERATED_UNIQUEARRAY_H
