#ifndef FIBGEN_H_
#define FIBGEN_H_

class FibGen {
    int count{ 0 };
    int max{};
    int temp{};
    int previous{ 0 };
    int current{ 1 };
    constexpr void next_fib();

public:
    FibGen() = default;
    explicit FibGen(int);
    int operator*() const;
    FibGen& operator++();
    FibGen operator++(int);
    bool operator==(const FibGen&) const;
    bool operator!=(const FibGen&) const;
    const FibGen& begin() const;
    const FibGen end() const;
    FibGen& operator=(FibGen&);


};

#endif