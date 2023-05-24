// fig08_01.cpp
// Demonstrating string assignment and concatenation.
#include <fmt/format.h> 
#include <iostream>
#include <string> 

int main() {
   std::string s1{"cat"};
   std::string s2; // initialized to the empty string
   std::string s3; // initialized to the empty string

   s2 = s1; // assign s1 to s2      
   s3.assign(s1); // assign s1 to s3
   std::cout << fmt::format("s1: {}\ns2: {}\ns3: {}\n\n", s1, s2, s3);

   s2.at(0) = 'r'; // modify s2 
   s3.at(2) = 'r'; // modify s3
   std::cout << fmt::format("After changes:\ns2: {}\ns3: {}", s2, s3);

   std::cout << "\n\nAfter concatenations:\n";
   std::string s4{s1 + "apult"}; // concatenation
   s1.append("acomb"); // create "catacomb"
   s3 += "pet"; // create "carpet" with overloaded +=
   std::cout << fmt::format("s1: {}\ns3: {}\ns4: {}\n", s1, s3, s4);

   // append locations 4 through end of s1 to
   // create string "comb" (s5 was initially empty)    
   std::string s5; // initialized to the empty string
   s5.append(s1, 4, s1.size() - 4);
   std::cout << fmt::format("s5: {}", s5);
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
