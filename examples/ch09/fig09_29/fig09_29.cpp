// fig09_29.cpp  
// Using the this pointer to refer to object members.
#include <fmt/format.h>
#include <iostream>

class Test {
public:
   explicit Test(int value);
   void print() const;
private:
   int m_x{0};
};

// constructor
Test::Test(int value) : m_x{value} {} // initialize x to value

// print x using implicit then explicit this pointers;
// the parentheses around *this are required due to precedence
void Test::print() const {
   // implicitly use the this pointer to access the member x
   std::cout << fmt::format("        m_x = {}\n", m_x);

   // explicitly use the this pointer and the arrow operator
   // to access the member x                                
   std::cout << fmt::format("  this->m_x = {}\n", this->m_x);

   // explicitly use the dereferenced this pointer and
   // the dot operator to access the member x         
   std::cout << fmt::format("(*this).m_x = {}\n", (*this).m_x);
}

int main() {
   const Test testObject{12}; // instantiate and initialize testObject
   testObject.print();
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
