#include "Word.h"
#include <stdexcept> 
#include <cstring>

Word::Word() : data(nullptr) {}

Word::Word(const char* str) {
    size_t len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
}

Word::Word(const char* arr, size_t size) {
    data = new char[size + 1];
    std::memcpy(data, arr, size);
    data[size] = '\0';
}

Word::Word(const Word& other) {
    size_t len = std::strlen(other.data);
    data = new char[len + 1];
    std::strcpy(data, other.data);
}

Word::Word(Word&& other) noexcept : data(other.data) {
    other.data = nullptr;
}

Word::~Word() {
    delete[] data;
}

Word& Word::operator=(const Word& other) {
    if (this != &other) {
        delete[] data;
        size_t len = std::strlen(other.data);
        data = new char[len + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

Word& Word::operator=(Word&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

bool Word::operator==(const Word& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool Word::operator<(const Word& other) const {
    return std::strcmp(data, other.data) < 0;
}

bool Word::startsWith(const char* prefix) const {
    size_t prefixLen = std::strlen(prefix);
    size_t dataLen = std::strlen(data);
    if (prefixLen > dataLen) return false;
    return std::strncmp(data, prefix, prefixLen) == 0;
}

void Word::toLowerCase() {
    for (size_t i = 0; data[i] != '\0'; ++i) {
        data[i] = std::tolower(data[i]);
    }
}

std::istream& operator>>(std::istream& in, Word& word) {
    char buffer[1024];
    in >> buffer;
    word = Word(buffer);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Word& word) {
    if (word.data) {
        out << word.data;
    }
    return out;
}
char& Word::operator[](size_t index) {
    if (index >= strlen(data)) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char& Word::operator[](size_t index) const {
    if (index >= strlen(data)) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}