#ifndef ITERATED_UNIQUEARRAY_H
#define ITERATED_UNIQUEARRAY_H

template <class Element, class Compare = std::equal_to<Element>>
class IteratedUniqueArray: public UniqueArray {
    int iterator;

public:
    UniqueArray(unsigned int size);
    UniqueArray(const UniqueArray& other);
    ~UniqueArray();
    UniqueArray& operator=(const UniqueArray&) = delete;
    bool remove(const Element& element);
    Element& getNext();
    Element& getFirst();

    class UniqueArrayIsEmptyException{};
};

#endif //ITERATED_UNIQUEARRAY_H
