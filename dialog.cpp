#include "Word.h"
#include "ArrayOfWords.h"
#include <iostream>

void interactiveMenu() {
    ArrayOfWords array;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\nInteractive Menu:\n";
        std::cout << "1. Add a word\n";
        std::cout << "2. Merge another array\n";
        std::cout << "3. Sort words\n";
        std::cout << "4. Display all words\n";
        std::cout << "5. Search for words starting with a character\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string input;
                std::cout << "Enter a word: ";
                std::cin >> input;
                array += Word(input.c_str());
                break;
            }
            case 2: {
                ArrayOfWords otherArray;
                int numWords;
                std::cout << "How many words to merge?: ";
                std::cin >> numWords;
                for (int i = 0; i < numWords; ++i) {
                    std::string input;
                    std::cout << "Enter word " << (i + 1) << ": ";
                    std::cin >> input;
                    otherArray += Word(input.c_str());
                }
                array += otherArray;
                break;
            }
            case 3: {
                array.sortWords();
                std::cout << "Words sorted alphabetically.\n";
                break;
            }
            case 4: {
                std::cout << "Current words: \n" << array << "\n";
                break;
            }
            case 5: {
                char ch;
                std::cout << "Enter the starting character: ";
                std::cin >> ch;
                ArrayOfWords subset = array.subset(ch);
                std::cout << "Words starting with '" << ch << "': \n" << subset << "\n";
                break;
            }
            case 0:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    interactiveMenu();
    return 0;
}