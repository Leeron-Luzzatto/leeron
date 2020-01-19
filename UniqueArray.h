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

    template<class iterator_element>
    class temp_iterator {
        UniqueArray* unique_array;
        int index;

        explicit temp_iterator(UniqueArray* unique_array, int index);
        int initializeIterator(int start=0) const;
        static const int end_unique_array = -1;
    public:
        temp_iterator(UniqueArray* unique_array);
        temp_iterator(const temp_iterator& i) = default;
        temp_iterator& operator=(const temp_iterator& other) = default;
        iterator_element& operator*() const;
        temp_iterator& operator++(); // postfix increment
        bool operator==(const temp_iterator& other) const;
        bool operator!=(const temp_iterator& other) const;
        friend class UniqueArray<Element, Compare>;
    };
    typedef temp_iterator<Element> iterator;
    typedef temp_iterator<const Element> const_iterator;
    friend class iterator;
    friend class const_iterator;

    iterator begin();
    iterator end();
    iterator begin() const;
    iterator end() const;
};

#include "UniqueArrayImp.h"

#endif //MTMPARKINGLOT_UNIQUEARRAY_H
