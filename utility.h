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

#include <assert.h>
#include "typedefs.h"

#ifndef UTILITY_H
#define UTILITY_H


namespace shk_fraction
{

// Utility functions

/**
   Computes greatest common divisor of two integers (fints)
   @param a fint
   @param b fint
   @returns gcd of a and b (fint)
*/
inline fint gcd(fint a, fint b)
{
   assert((a>=0)&&(b>=0));
   fint r;
   if (a==0) return b;
   if (b==0) return a;
   while (r = a%b)
   {
      a = b;
      b = r;
   }
   return b;
}


// Overflow checking functions
/**
    Checks for overflow in addition, produces exception if overflow happens
    @param a addend
    @param b addend
    @param c sum
    @throws ErrorAddOverflow
*/
inline void CheckAddOvf(fint a, fint b, fint c)
{
   const fint MASK = ((static_cast<fint>(1)<<(sizeof(fint)*8-1)));
   if ( (~(a^b)) & (a^c) & MASK ) throw ErrorAddOverflow;
}


/**
    Checks for overflow in multiplication, produces exception if overflow happens
    @param a multiplicand
    @param b multiplicand
    @param c product
    @throws ErrorMultOverflow
*/inline void CheckMultOvf(fint a, fint b, fint c)
{
   if ( (c/a) != b ) throw ErrorMultOverflow;
}


} //namespace

#endif
