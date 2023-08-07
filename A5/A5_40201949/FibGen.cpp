/**
 * COMP 5421 Advanced C++ Programming
 * Assignment 5 - Due August 13th, 2023
 * Thomas Roy - 40291949
**/
#include "FibGen.h"

/**
 * The function calculates the next Fibonacci number in a sequence.
 */
constexpr void FibGen::next_fib() {
    temp = previous + current;
    previous = current;
    current = temp;
}

/**
 * The FibGen constructor initializes the maximum value for the Fibonacci sequence.
 *
 * @param max The parameter "max" is an integer that represents the maximum value for the Fibonacci
 * sequence that will be generated.
 */
FibGen::FibGen(int max) : max{ max } {};

/**
 * The above function returns the current Fibonacci number.
 *
 * @return The current value of the Fibonacci sequence.
 */
int FibGen::operator*() const { return current; }

/**
 * The above function is an overloaded pre-increment operator for a Fibonacci number generator class.
 *
 * @return The object itself is being returned.
 */
FibGen& FibGen::operator++() {
    next_fib();
    ++count;
    return *this;
}

/**
 * The above function overloads the post-increment operator for the FibGen class.
 *
 * @param  The above code snippet is defining the post-increment operator++ for the class FibGen.
 * @return The `operator++(int)` function is returning a copy of the current `FibGen` object before it
 * is incremented.
 */
FibGen FibGen::operator++(int) {
    auto temp{ *this };
    ++(*this);
    return temp;
}

/**
 * The function checks if the count of two FibGen objects are equal.
 *
 * @param fg The parameter "fg" is of type "FibGen", which is the class that the operator function
 * belongs to.
 * @return a boolean value.
 */
bool FibGen::operator==(const FibGen& fg) const {
    return count == fg.count;
}

/**
 * The function checks if two FibGen objects are not equal.
 *
 * @param fg The parameter `fg` is of type `FibGen`, which means it is an object of the `FibGen` class.
 * @return The operator!= function is returning a boolean value.
 */
bool FibGen::operator!=(const FibGen& fg) const {
    return !(*this == fg);
}
/**
 * The function returns a reference to the current object.
 *
 * @return The `begin()` function is returning a reference to the current instance of the `FibGen`
 * class.
 */

const FibGen& FibGen::begin() const {
    return *this;
}

/**
 * The end() function returns a FibGen object with the count set to the maximum value.
 *
 * @return The `end()` function is returning an instance of the `FibGen` class.
 */
const FibGen FibGen::end() const {
    auto last = FibGen();
    last.count = max;
    return last;
}

/**
 * The function assigns the values of a FibGen object to another FibGen object.
 *
 * @return a reference to the current object, which is accessed using the "this" pointer.
 */
FibGen& FibGen::operator=(FibGen& fg) {
    max = fg.max;
    count = fg.count;
    current = fg.current;
    return *this;
}

