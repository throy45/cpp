// fig10_08.cpp
// Aiming a derived-class pointer at a base-class object.
#include "SalariedEmployee.h"
#include "SalariedCommissionEmployee.h"

int main() {
   SalariedEmployee salaried{"Sue Jones", 500.0};

   // aim derived-class pointer at base-class object                 
   // Error: a SalariedEmployee is not a SalariedCommissionEmployee
   SalariedCommissionEmployee* salariedCommissionPtr{&salaried};
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
