#ifndef MTMPARKINGLOT_UNIQUEARRAY_H
#define MTMPARKINGLOT_UNIQUEARRAY_H

template <class Element, class Compare = std::equal_to<Element>>
class UniqueArray {
	Element** data;
	const int size;

    bool availableIndex(unsigned int& index);
public:
    UniqueArray(unsigned int size);
    UniqueArray(const UniqueArray& other);
    ~UniqueArray();
    UniqueArray& operator=(const UniqueArray&) = delete;
    unsigned int insert(const Element& element);
    bool getIndex(const Element& element, unsigned int& index) const;
    const Element* operator[] (const Element& element) const;
    bool remove(const Element& element);
    unsigned int getCount() const;
    unsigned int getSize() const;

    class Filter {
    public:
        virtual bool operator() (const Element&) const = 0;
    };
    UniqueArray filter(const Filter& f) const;
    class UniqueArrayIsFullException{};

    class iterator {
        UniqueArray* unique_array;
        int index;

        explicit iterator(UniqueArray* unique_array, int index);
        int initializeIterator(int start=0) const;
        static const int end_unique_array = -1;
    public:
        iterator(UniqueArray* unique_array);
        iterator(const iterator& i) = default;
        iterator& operator=(const iterator& other) = default;
        Element& operator*() const;
        iterator& operator++(); // postfix increment
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
        friend class UniqueArray<Element, Compare>;
    };
    friend class iterator;
    iterator begin();
    iterator end();
};

#include "UniqueArrayImp.h"

#endif //MTMPARKINGLOT_UNIQUEARRAY_H
