#include <cstdlib>      //system()
#include "../hpp/RPN.hpp"
#include "../hpp/Complejo.hpp"
#include "../hpp/Rational.hpp"
#include <iostream>

using namespace std;

int main(void) {
   bool exitMain = false;
   int option;

   system("clear");
   do {
      cout << "Reverse Polish Notation Calculator (RPN Calculator)\n"
           << "---------------------------------------------------\n" << endl;

      cout << "    0.- Exit\n"
           << "    1.- Set & evaluate int expression\n"
           << "    2.- Set & evaluate float expression\n"
           << "    3.- Set & evaluate complex expression\n"
           << "    4.- Set & evaluate rational expression\n" << endl;

      cin >> option;
      system("clear");
      switch (option) {
         case 0:
            exitMain = true;
            break;
         case 1: {
            RPN<int> intCalculator;
            intCalculator.run();
            break;
         }
         case 2: {
            RPN<float> floatCalculator;
            floatCalculator.run();
            break;
         }
         case 3: {
            RPN<Complejo> complexCalculator;
            complexCalculator.run();
            break;
         }
         case 4: {
            RPN<Rational> rationalCalculator;
            rationalCalculator.run();
            break;
         }
         default:
            cout << "Wrong choice, please try again...\n" << endl;
      }
   } while(!exitMain);
   return 0;
}
