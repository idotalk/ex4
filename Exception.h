#ifndef MTM4_EXCEPTION_H
#define MTM4_EXCEPTION_H
#include <stdexcept>
#include <string>

class DeckFileNotFound : public std::logic_error {
public:
    DeckFileNotFound() : std::logic_error("Deck File Error: File not found"){};;
};

class DeckFileFormatError: public std::logic_error {
public:
    explicit DeckFileFormatError(int line) : std::logic_error("Deck File Error: File format error in line "+
                                                                std::to_string(line)){}

};

class DeckFileInvalidSize : public std::logic_error {
public:
    DeckFileInvalidSize() : std::logic_error("Deck File Error: Deck size is invalid"){};
};

#endif // MTM4_EXCEPTION_H