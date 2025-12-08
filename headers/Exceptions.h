//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_EXCEPTIONS_H
#define GAME_OOP_PROJECT_EXCEPTIONS_H

#endif //GAME_OOP_PROJECT_EXCEPTIONS_H*/

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <exception>
#include <string>

class GameException : public std::exception {
protected:
    std::string msg;
public:
    explicit GameException(std::string m) : msg(std::move(m)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class FileReadException : public GameException {
public:
    explicit FileReadException(const std::string& filename)
        : GameException("File read error: " + filename) {}
};

class ContainerException : public GameException {
public:
    explicit ContainerException(const std::string& m) : GameException(m) {}
};

class DataFormatException : public GameException {
public:
    explicit DataFormatException(const std::string& m) : GameException(m) {}
};

#endif // OOP_EXCEPTIONS_H

