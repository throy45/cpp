// Fig. 10.32: Commission.cpp
// Commission member-function definitions.
#include <fmt/format.h>
#include <stdexcept>
#include "Commission.h" // class definition

// constructor                                                        
Commission::Commission(double grossSales, double commissionRate)         
   : m_grossSales{grossSales}, m_commissionRate{commissionRate} {

   if (m_grossSales < 0.0) {
      throw std::invalid_argument("Gross sales must be >= 0.0");
   } 

   if (m_commissionRate <= 0.0 || m_commissionRate >= 1.0) {
      throw std::invalid_argument(
         "Commission rate must be > 0.0 and < 1.0");
   } 
}                                      

// override CompensationModel pure virtual function earnings
double Commission::earnings() const {
   return m_grossSales * m_commissionRate;       
}                                            

// override CompensationModel pure virtual function toString  
std::string Commission::toString() const {                       
   return fmt::format("gross sales: ${:.2f}; commission rate: {:.2f}", 
      m_grossSales, m_commissionRate);
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
