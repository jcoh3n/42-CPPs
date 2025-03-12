#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &span) {
    *this = span;
}

Span &Span::operator=(const Span &span) {
    if (this == &span)
        return *this;
    _maxSize = span._maxSize;
    _numbers = span._numbers;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize) // si la taille du vector est >= a la taille max
        throw std::length_error("Span is already full.");
    _numbers.push_back(n);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2) // si il n'y a pas assez de nombre 
        throw std::logic_error("Not enough numbers to calculate the span.");
    std::vector<int> sorted = _numbers; // creation d'un temp vector pour pouvoir le trier
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0]; // initialisation de la valeur la plus petite
    for (unsigned int i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate the span.");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted[sorted.size() - 1] - sorted[0]; // retourne la difference entre le premier et le dernier element
}
