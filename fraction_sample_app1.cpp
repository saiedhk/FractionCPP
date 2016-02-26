/**********************************************************************

   Project: C++ Fractional Arithmetic Library with Overflow Checking

   Language: C++ 2007	   
   Author: Saied H. Khayat
   Date:   March 2012
   URL: https://github.com/saiedhk
   
   Copyright Notice: Free use of this library is permitted under the
   guidelines and in accordance with the MIT License (MIT).
   http://opensource.org/licenses/MIT

**********************************************************************/

/*
   Sample program for Fraction Class

   This program to convert a fraction (rational number) to
   it continued fraction form. It uses 'Fraction' class,
   and interacts with the user through the command line.

   The user is expected to enter the name of the executable file at
   the command prompt along with two input integers, say a and b
   (both of long long type). Then it prints out the fraction a/b in
   its continued fraction form.

   Example1s:

   C:\> fraction_to_continued_fraction.exe 7340 2838  <enter>
   (3670/1419) = [2,1,1,2,2,1,1,9,5]

   C:\> fraction_to_continued_fraction.exe 5039288420 483713434199  <enter>
   (5039288420/483713434199) = [0,95,1,85,1,1,46,1,17,3,5,3,1,1,17,5,3]

*/

#include <sstream>
#include "fraction.h"

using namespace std;
using namespace shk_fraction;

const int NARGS = 3;


int main( int argc, char* argv[] )
{
   if ( argc != NARGS )
   {
      cerr << "Usage: " << argv[0] << " numerator denomerator <enter>\n";
      exit(1);
   }

   fint num, denom;

   istringstream arg1(argv[1]);
   istringstream arg2(argv[2]);
   if ( !(arg1 >> num) || !(arg2 >> denom) )
   {
      cerr << "fatal: one or two inputs are invalid!\n";
      exit(1);
   }

   // set fraction
   Fraction fraction;
   try {
       fraction.set(num,denom);
   }
   catch (ErrorCode e) {
       cerr << "fatal: zero denominator\n"; exit(1);
   }

   // start converting
   cout << fraction << " = [";

   fint numerator, a;

   do {
      a = fraction.properize();
      cout << a << ",";
      numerator = fraction.numerator();
      fraction = 1 / fraction;
   } while (numerator != 1);

   cout << fraction.numerator() << "]\n";

   return 0;
}
