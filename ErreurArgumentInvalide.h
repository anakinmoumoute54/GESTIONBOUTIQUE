#pragma once
#include <stdexcept>
#include <string>

class ErreurArgumentInvalide : public std::invalid_argument {
public:
    explicit ErreurArgumentInvalide(const std::string& message);
};