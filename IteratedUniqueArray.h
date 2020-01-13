#ifndef ITERATED_UNIQUEARRAY_H
#define ITERATED_UNIQUEARRAY_H

#include "UniqueArray.h"
#include <iostream>

template <class Element, class Compare = std::equal_to<Element>>
class IteratedUniqueArray: public UniqueArray<Element, Compare> {
    int iterator;

public:
    IteratedUniqueArray(unsigned int size);
    IteratedUniqueArray(const UniqueArray& other);
    ~IteratedUniqueArray();
    IteratedUniqueArray& operator=(const UniqueArray&) = delete;
    bool remove(const Element& element);
    Element& getNext();
    Element& getFirst();

    class Filter {
    public:
        virtual bool operator() (const Element&) const = 0;
    };
    IteratedUniqueArray filter(const Filter& f) const;
    class IteratedUniqueArrayIsEmptyException{};
};

#endif //ITERATED_UNIQUEARRAY_H
