#include "ArrayOfWords.h"
#include <algorithm>

ArrayOfWords::ArrayOfWords() : words(nullptr), size(0), capacity(0) {}

ArrayOfWords::ArrayOfWords(const Word& word) : size(1), capacity(1) {
    words = new Word[1];
    words[0] = word;
}

ArrayOfWords::ArrayOfWords(const Word* wordArray, size_t arraySize) : size(arraySize), capacity(arraySize) {
    words = new Word[arraySize];
    for (size_t i = 0; i < arraySize; ++i) {
        words[i] = wordArray[i];
    }
}

ArrayOfWords::ArrayOfWords(const ArrayOfWords& other) : size(other.size), capacity(other.capacity) {
    words = new Word[other.capacity];
    for (size_t i = 0; i < other.size; ++i) {
        words[i] = other.words[i];
    }
}

ArrayOfWords::ArrayOfWords(ArrayOfWords&& other) noexcept : words(other.words), size(other.size), capacity(other.capacity) {
    other.words = nullptr;
    other.size = 0;
    other.capacity = 0;
}

ArrayOfWords::~ArrayOfWords() {
    delete[] words;
}

ArrayOfWords& ArrayOfWords::operator=(const ArrayOfWords& other) {
    if (this != &other) {
        delete[] words;
        size = other.size;
        capacity = other.capacity;
        words = new Word[capacity];
        for (size_t i = 0; i < size; ++i) {
            words[i] = other.words[i];
        }
    }
    return *this;
}

ArrayOfWords& ArrayOfWords::operator=(ArrayOfWords&& other) noexcept {
    if (this != &other) {
        delete[] words;
        words = other.words;
        size = other.size;
        capacity = other.capacity;
        other.words = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

void ArrayOfWords::resize() {
    capacity = capacity == 0 ? 1 : capacity * 2;
    Word* newWords = new Word[capacity];
    for (size_t i = 0; i < size; ++i) {
        newWords[i] = std::move(words[i]);
    }
    delete[] words;
    words = newWords;
}

ArrayOfWords& ArrayOfWords::operator+=(const Word& word) {
    if (size == capacity) {
        resize();
    }
    words[size++] = word;
    return *this;
}

ArrayOfWords& ArrayOfWords::operator+=(const ArrayOfWords& other) {
    for (size_t i = 0; i < other.size; ++i) {
        *this += other.words[i];
    }
    return *this;
}

Word& ArrayOfWords::operator[](size_t index) {
    return words[index];
}

const Word& ArrayOfWords::operator[](size_t index) const {
    return words[index];
}

ArrayOfWords ArrayOfWords::subset(char ch) const {
    ArrayOfWords result;
    for (size_t i = 0; i < size; ++i) {
        if (std::tolower(words[i][0]) == std::tolower(ch)) {
            result += words[i];
        }
    }
    return result;
}

void ArrayOfWords::sortWords() {
    std::sort(words, words + size);
}

std::istream& operator>>(std::istream& in, ArrayOfWords& array) {
    size_t count;
    in >> count;
    for (size_t i = 0; i < count; ++i) {
        Word word;
        in >> word;
        array += word;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const ArrayOfWords& array) {
    for (size_t i = 0; i < array.size; ++i) {
        out << array.words[i] << " ";
    }
    return out;
}