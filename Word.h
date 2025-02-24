// Word.h
#ifndef WORD_H
#define WORD_H

#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

/**
 * @class Word
 * @brief Represents a single word (character string without whitespace).
 *
 * This class provides functionality to handle words, including initialization,
 * comparison, and various operations like converting to lowercase and checking prefixes.
 */
class Word {
private:
    char* data; ///< Dynamic array to store the word

public:
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    /**
     * @brief Default constructor.
     * Initializes the word to an empty state.
     */
    Word();

    /**
     * @brief Constructor with C-string initialization.
     * @param str Null-terminated C-string.
     */
    Word(const char* str);

    /**
     * @brief Constructor with character array and size.
     * @param arr Non-null-terminated character array.
     * @param size Size of the array.
     */
    Word(const char* arr, size_t size);

    /**
     * @brief Copy constructor.
     * @param other Another Word instance to copy from.
     */
    Word(const Word& other);

    /**
     * @brief Move constructor.
     * Transfers ownership of the word data.
     * @param other Another Word instance to move from.
     */
    Word(Word&& other) noexcept;

    /**
     * @brief Destructor.
     * Releases dynamically allocated memory.
     */
    ~Word();

    /**
     * @brief Copy assignment operator.
     * @param other Another Word instance to copy from.
     * @return Reference to this instance.
     */
    Word& operator=(const Word& other);

    /**
     * @brief Move assignment operator.
     * Transfers ownership of the word data.
     * @param other Another Word instance to move from.
     * @return Reference to this instance.
     */
    Word& operator=(Word&& other) noexcept;

    /**
     * @brief Comparison operator (equality).
     * @param other Another Word instance to compare with.
     * @return True if the words are equal.
     */
    bool operator==(const Word& other) const;

    /**
     * @brief Comparison operator (less-than).
     * @param other Another Word instance to compare with.
     * @return True if this word is less than the other.
     */
    bool operator<(const Word& other) const;

    /**
     * @brief Checks if the word starts with the given prefix.
     * @param prefix Null-terminated C-string prefix.
     * @return True if the word starts with the prefix.
     */
    bool startsWith(const char* prefix) const;

    /**
     * @brief Converts the word to lowercase.
     */
    void toLowerCase();

    /**
     * @brief Input operator for reading a word.
     * @param in Input stream.
     * @param word Word instance to read into.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>(std::istream& in, Word& word);

    /**
     * @brief Output operator for writing a word.
     * @param out Output stream.
     * @param word Word instance to write.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Word& word);
};

#endif 

