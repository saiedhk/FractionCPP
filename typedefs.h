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

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

namespace shk_fraction
{

/**
   Defines 'fint', the main integer type used in Fraction class.
*/
typedef signed long long int fint;


/**
   Defines 'real', the main floating-point type in Fraction class.
*/
typedef double real;


/**
   Defines exception codes.
*/
typedef enum
{
   Ok,
   ErrorDivideByZero,
   ErrorAddOverflow,
   ErrorMultOverflow
} ErrorCode;

} // namespace
#endif
