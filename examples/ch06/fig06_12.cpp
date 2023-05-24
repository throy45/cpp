// fig06_12.cpp
// Compute the product of an array's elements using accumulate.
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <numeric>

int multiply(int x, int y) {
   return x * y;
}

int main() {
   constexpr std::array integers{1, 2, 3, 4, 5};

   std::cout << fmt::format("Product of integers: {}\n", std::accumulate(
      std::begin(integers), std::end(integers), 1, multiply));

   std::cout << fmt::format("Product of integers with a lambda: {}\n",
      std::accumulate(std::begin(integers), std::end(integers), 1,
         [](const auto& x, const auto& y) {return x * y; }));
}


/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/

