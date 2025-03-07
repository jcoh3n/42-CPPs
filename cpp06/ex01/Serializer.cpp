#include "Serializer.hpp"
#include <stdexcept>

uintptr_t Serializer::serialize(Data* ptr) {
    if (ptr == NULL) {
        throw std::invalid_argument("Pointer cannot be null");
    }
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

