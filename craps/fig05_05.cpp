// fig05_05.cpp
// Craps simulation.
#include <iostream>
#include <random>
using namespace std;

int rollDice(); // rolls dice, calculates and displays sum
int playOneGame();

int main()
{
   int numGames{0}; // number of games to play
   cout << "Enter number of games: ";
   cin >> numGames;
   int numWins{0}; // number of games won
   for (int i{1}; i <= numGames; ++i)
   {
      numWins += playOneGame();
   }
   cout << "The player won " << numWins << " out of " << numGames << " games.\n";
   cout << "Wins percentage: " << static_cast<double>(numWins) / numGames * 100 << "%\n";
}

int playOneGame()
{
   // scoped enumeration with constants that represent the game status
   enum class Status
   {
      keepRolling,
      won,
      lost
   };

   int myPoint{0};                         // point if no win or loss on first roll
   Status gameStatus{Status::keepRolling}; // game is not over

   cout << endl;
   // determine game status and point (if needed) based on first roll
   switch (const int sumOfDice{rollDice()})
   {
   case 7:  // win with 7 on first roll
   case 11: // win with 11 on first roll
      gameStatus = Status::won;
      break;
   case 2:  // lose with 2 on first roll
   case 3:  // lose with 3 on first roll
   case 12: // lose with 12 on first roll
      gameStatus = Status::lost;
      break;
   default:                // did not win or lose, so remember point
      myPoint = sumOfDice; // remember the point
      cout << "Point is " << myPoint << endl;
      break; // optional (but recommended) at end of switch
   }

   // while game is not complete
   while (Status::keepRolling == gameStatus)
   { // not won or lost
      // roll dice again and determine game status
      if (const int sumOfDice{rollDice()}; sumOfDice == myPoint)
      {
         gameStatus = Status::won;
      }
      else if (sumOfDice == 7)
      { // lose by rolling 7 before point
         gameStatus = Status::lost;
      }
   }

   // display won or lost message
   if (Status::won == gameStatus)
   {
      cout << "Player wins" << endl
           << endl;
      return 1;
   }
   else
   {
      cout << "Player loses" << endl
           << endl;
      return 0;
   }
}

// roll dice, calculate sum and display results
int rollDice()
{
   // set up random-number generation
   static random_device rd;                   // used to seed the default_random_engine
   static default_random_engine engine{rd()}; // rd() produces a seed
   static uniform_int_distribution randomDie{1, 6};

   const int die1{randomDie(engine)}; // first die roll
   const int die2{randomDie(engine)}; // second die roll
   const int sum{die1 + die2};        // compute sum of die values

   // display results of this roll
   cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

   return sum;
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
