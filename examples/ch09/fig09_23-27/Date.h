// Fig. 9.23: Date.h 
// Date class definition; member functions defined in Date.cpp
#pragma once // prevent multiple inclusions of header
#include <string>

class Date {
public:
   static const int monthsPerYear{12}; // months in a year
   Date(int year, int month, int day);
   std::string toString() const; // date string in yyyy-mm-dd format
   ~Date(); // implementation displays when destruction occurs
private:
   int m_year; // any year
   int m_month; // 1-12 (January-December)
   int m_day; // 1-31 based on month

   // utility function to check if day is proper for month and year
   bool checkDay(int day) const;
};


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
