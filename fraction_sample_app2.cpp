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

   This program computes the sum of the first N terms of a series of fractions.
   The summation is shown in LaTeX as follows:
   S_n = \sum_{i=1}^N \frac{(-1)^i}{i}

   Example:
   C:\> fractional_series1.exe 42 <enter>
   N=42    Sum = (283640530031256287/219060189739591200)

*/

#include <sstream>
#include "fraction.h"

using namespace std;
using namespace shk_fraction;

const int NARGS = 2;

int main( int argc, char* argv[] )
{
   if ( argc != NARGS )
   {
      cerr << "Usage: " << argv[0] << " N <enter>\n";
      exit(1);
   }

   int N;

   istringstream arg1(argv[1]);
   if ( !(arg1 >> N) )
   {
      cerr << "fatal: bad input!\n";
      exit(1);
   }

   Fraction fraction, sum;
   try
   {
      sum.set(1,1);
      int flag = 1;
      for (fint i=2; i<N; i++)
      {
         if (flag>0)
            fraction.set(1,i);
         else
            fraction.set(-1,i);
         sum = sum + fraction;
         flag = -flag;
      }
      cout << "N=" << N << "\tSum = " << sum << endl;
   }
   catch (ErrorCode e)
   {
      switch (e) {
         case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
         case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
         case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
         default: cerr << "Invalid error code!!!\n";
      }
   }

   return 0;
}

