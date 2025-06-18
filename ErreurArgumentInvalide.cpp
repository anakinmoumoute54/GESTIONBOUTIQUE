#include "ErreurArgumentInvalide.h"

ErreurArgumentInvalide::ErreurArgumentInvalide(const std::string& message)
    : std::invalid_argument("Erreur : " + message) {}