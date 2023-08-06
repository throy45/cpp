#include "FibGen.h"

constexpr void FibGen::next_fib() {
    temp = previous + current;
    previous = current;
    current = temp;
}

FibGen::FibGen(int max) : max{ max } {};

int FibGen::operator*() const { return current; }

FibGen& FibGen::operator++() {
    next_fib();
    ++count;
    return *this;
}

FibGen FibGen::operator++(int) {
    auto temp{ *this };
    ++(*this);
    return temp;
}

bool FibGen::operator==(const FibGen& fg) const {
    return count == fg.count;
}

bool FibGen::operator!=(const FibGen& fg) const {
    return !(*this == fg);
}

const FibGen& FibGen::begin() const {
    return *this;
}

const FibGen FibGen::end() const {
    auto last = FibGen();
    last.count = max;
    return last;
}

FibGen& FibGen::operator=(FibGen& fg) {
    max = fg.max;
    count = fg.count;
    current = fg.current;
    return *this;
}

