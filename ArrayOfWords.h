#ifndef ARRAYOFWORDS_H
#define ARRAYOFWORDS_H

#include "Word.h"

class ArrayOfWords {
private:
    Word* words;
    size_t size;
    size_t capacity;

    void resize();

public:
    ArrayOfWords();
    ArrayOfWords(const Word& word);
    ArrayOfWords(const Word* wordArray, size_t arraySize);
    ArrayOfWords(const ArrayOfWords& other);
    ArrayOfWords(ArrayOfWords&& other) noexcept;
    ~ArrayOfWords();

    ArrayOfWords& operator=(const ArrayOfWords& other);
    ArrayOfWords& operator=(ArrayOfWords&& other) noexcept;

    ArrayOfWords& operator+=(const Word& word);
    ArrayOfWords& operator+=(const ArrayOfWords& other);

    Word& operator[](size_t index);
    const Word& operator[](size_t index) const;

    ArrayOfWords subset(char ch) const;

    void sortWords();

    friend std::istream& operator>>(std::istream& in, ArrayOfWords& array);
    friend std::ostream& operator<<(std::ostream& out, const ArrayOfWords& array);
};

#endif 



