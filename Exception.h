#ifndef MTM4_EXCEPTION_H
#define MTM4_EXCEPTION_H
#include <stdexcept>
#include <string>

class DeckFileNotFound : public std::exception {
public:
    DeckFileNotFound() : m_message("Deck File Error: File not found"){};;
    const char* what() const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

class DeckFileFormatError: public std::exception {
public:
    explicit DeckFileFormatError(int line){
        m_line = line;
        m_message="Deck File Error: File format error in line ";
    }
    const char* what() const noexcept override {
        std::string line = std::to_string(m_line);
        std::string msg = (m_message + line);
        return msg.c_str();
    }
private:
    std::string m_message;
    int m_line;

};

class DeckFileInvalidSize : public std::exception {
public:
    DeckFileInvalidSize() : m_message("Deck File Error: Deck size is invalid"){};
    const char* what() const noexcept override {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

#endif // MTM4_EXCEPTION_H