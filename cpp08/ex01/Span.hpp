#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
public:
    Span(unsigned int N);
    Span(const Span &span);
    Span &operator=(const Span &span);
    ~Span();
    void addNumber(int N);
    int shortestSpan();
    int longestSpan();
    template <typename Range>
    void addRange(Range begin, Range end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize) // taille du vector + la taille de la range doit etre < _maxSize
            throw std::length_error("Adding this range would exceed Span capacity");
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif