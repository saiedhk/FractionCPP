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

#include "typedefs.h"

#ifndef SHK_FRACTION_H
#define SHK_FRACTION_H

// comment the following to disable run-time overflow checking
#define OVFCHECK

#include <iostream>
using std::ostream;


namespace shk_fraction
{


/**
   Defines 'Fraction' class.

   A fraction is the same as a rational number in mathematics.
   A rational number is a number that can be written as a ratio of two integers.

   In Fraction class, a Frction instance is always maintained in its reduced form.
   The reduced form of a Fraction consists of denominator and numerator that
   are relatively prime.

   This class is fully checked against overflow and divide-by-zero conditions.
   When such errors occur, an exception is generated to warn the caller.

   The integers representing the numerator and denomerator of a fraction are of
   type 'fint'. A 'fint' is a signed long long int.
*/
class Fraction
{

   public:

      //---------------------------
      // constructors
      //---------------------------

      /**
         Contructs the default Fraction instance: 0/1.
      */
      Fraction(void);

      /**
         Contructs the Fraction instance: a/1.
         @param a (of type fint)
      */
      Fraction(fint a);

      /**
         Contructs the Fraction instance: a/1.
         @param a numerator (of type fint)
         @param b denominator (of type fint)
      */
      Fraction(fint a, fint b);

      //---------------------------
      // accessors
      //---------------------------

      /**
         Gets the numerator of Fraction.
      */
      fint numerator(void) const;         //

      /**
         Gets the denominator of Fraction.
      */
      fint denominator(void) const;

      /**
         Gets the sign of Fraction.
      */
      int sign(void) const;

      /**
         Gets the floating-point value of Fraction.
      */
      double realValue(void) const;

      /**
         Gets the integer part of the floating-point value of Fraction.
      */
      fint integerPart(void) const;

      /**
         Gets the fractional part of the floating-point value of Fraction.
      */
      double fractionalPart(void) const;


      //---------------------------
      // mutators
      //---------------------------

      /**
         Sets the numerator and denominator of Fraction.
         @param a numerator (of type fint)
         @param b denominator (of type fint)
      */
      void set(fint a, fint b);

      /**
         Sets the numerator of Fraction.
         @param a numerator (of type fint)
      */
      void setNum(fint a);

      /**
         Sets the numerator of Fraction.
         @param b denominator (of type fint)
      */
      void setDenom(fint b);

      /**
         Negates the sign of Fraction.
      */
      void negate(void);

      /**
         Converts Fraction to a proper fraction (i.e., a fraction that is less than 1).
         @returns the integer part of Fraction
      */
      fint properize(void);


      //---------------------------
      // Overloaded operators
      //---------------------------

      /**
         Checks equality of two Fractions.
         @param left Fraction
         @param right Fraction
         @returns true if equal, false if not equal
      */
      friend bool operator==(const Fraction& left, const Fraction& right);

      /**
         Checks inequality of two Fractions.
         @param left Fraction
         @param right Fraction
         @returns true if not equal, false if equal
      */
      friend bool operator!=(const Fraction& left, const Fraction& right);

      /**
         Compares two Fractions.
         @param left Fraction
         @param right Fraction
         @returns true if left > right, false otherwise
      */
      friend bool operator>(const Fraction& left, const Fraction& right);

      /**
         Compares two Fractions.
         @param left Fraction
         @param right Fraction
         @returns true if left < right, false otherwise
      */
      friend bool operator<(const Fraction& left, const Fraction& right);

      /**
         Compares two Fractions.
         @param left Fraction
         @param right Fraction
         @returns true if left >= right, false otherwise
      */
      friend bool operator>=(const Fraction& left, const Fraction& right);

      /**
         Compares two Fractions.
         @param left Fraction
         @param right Fraction
         @returns true if left <= right, false otherwise
      */
      friend bool operator<=(const Fraction& left, const Fraction& right);

      /**
         Checks equality of a Fraction and a real.
         @param left Fraction
         @param right real
         @returns true if left=right, false otherwise
      */
      friend bool operator==(const Fraction& left, real right);

      /**
         Checks inequality of a Fraction and a real.
         @param left Fraction
         @param right real
         @returns true if left != right, false otherwise
      */
      friend bool operator!=(const Fraction& left, real right);

      /**
         Compares a Fraction with a real.
         @param left Fraction
         @param right real
         @returns true if left > right, false otherwise
      */
      friend bool operator>(const Fraction& left, real right);

      /**
         Compares a Fraction with a real.
         @param left Fraction
         @param right real
         @returns true if left < right, false otherwise
      */
      friend bool operator<(const Fraction& left, real right);

      /**
         Compares a Fraction with a real.
         @param left Fraction
         @param right real
         @returns true if left >= right, false otherwise
      */
      friend bool operator>=(const Fraction& left, real right);

      /**
         Compares a Fraction with a real.
         @param left Fraction
         @param right real
         @returns true if left <= right, false otherwise
      */
      friend bool operator<=(const Fraction& left, real right);

      /**
         Checks equality of a Fraction and a real.
         @param left real
         @param right Fraction
         @returns true if left=right, false otherwise
      */
      friend bool operator==(real left, const Fraction& right);

      /**
         Checks equality of a Fraction and a real.
         @param left real
         @param right Fraction
         @returns true if left != right, false otherwise
      */
      friend bool operator!=(real left, const Fraction& right);

      /**
         Compares a Fraction with a real.
         @param left real
         @param right Fraction
         @returns true if left > right, false otherwise
      */
      friend bool operator>(real left, const Fraction& right);

      /**
         Compares a Fraction with a real.
         @param left real
         @param right Fraction
         @returns true if left < right, false otherwise
      */
      friend bool operator<(real left, const Fraction& right);

      /**
         Compares a Fraction with a real.
         @param left real
         @param right Fraction
         @returns true if left >= right, false otherwise
      */
      friend bool operator>=(real left, const Fraction& right);

      /**
         Compares a Fraction with a real.
         @param left real
         @param right Fraction
         @returns true if left <= right, false otherwise
      */
      friend bool operator<=(real left, const Fraction& right);

      /**
         Adds two Fractions.
         @param left Fraction
         @param right Fraction
         @returns Fraction
      */
      friend Fraction operator+(const Fraction& left, const Fraction& right);

      /**
         Subtracts two Fractions.
         @param left Fraction
         @param right Fraction
         @returns Fraction
      */
      friend Fraction operator-(const Fraction& left, const Fraction& right);

      /**
         Mulitplies two Fractions.
         @param left Fraction
         @param right Fraction
         @returns Fraction
      */
      friend Fraction operator*(const Fraction& left, const Fraction& right);

      /**
         Divides two Fractions.
         @param left Fraction
         @param right Fraction
         @returns Fraction
      */
      friend Fraction operator/(const Fraction& left, const Fraction& right);

      /**
         Adds a Fraction and an integer
         @param left Fraction
         @param right fint
         @returns Fraction
      */
      friend Fraction operator+(const Fraction& left, fint right);

      /**
         Subtracts an integer from a Fraction
         @param left Fraction
         @param right fint
         @returns Fraction
      */
      friend Fraction operator-(const Fraction& left, fint right);

      /**
         Multiplies a Fraction by an integer
         @param left Fraction
         @param right fint
         @returns Fraction
      */
      friend Fraction operator*(const Fraction& left, fint right);

      /**
         Divides a Fraction by an integer
         @param left Fraction
         @param right fint
         @returns Fraction
      */
      friend Fraction operator/(const Fraction& left, fint right);

      /**
         Adds a Fraction and an integer
         @param left fint
         @param right Fraction
         @returns Fraction
      */
      friend Fraction operator+(fint left, const Fraction& right);

      /**
         Subtracts a Fraction from an integer
         @param left fint
         @param right Fraction
         @returns Fraction
      */
      friend Fraction operator-(fint left, const Fraction& right);

      /**
         Multiplies an integer by a Fraction
         @param left Fraction
         @param right fint
         @returns Fraction
      */
      friend Fraction operator*(fint left, const Fraction& right);

      /**
         Divides an integer by a Fraction
         @param left Fraction
         @param right fint
         @returns Fraction
      */
      friend Fraction operator/(fint left, const Fraction& right);

      /**
         Negates a Fraction
         @param a Fraction
         @returns Fraction
      */
      friend Fraction operator-(const Fraction& f);

      /**
         Sends a Fraction to an output stream
         @param f Fraction
         @returns reference to an output stream
      */
      friend ostream& operator<<(ostream& out, const Fraction& f);

   private:

      fint num;                        // numerator
      fint denom;                      // denominator

      void reduce(void);               // reduces fraction to its irreducible form

      fint compare(Fraction f) const;  // Compares fraction against another fraction f
                                       // returns 0 if equal, negative if less than r,
                                       // positive if greater than r
};


} // namespace shk_fraction
#endif // SHK_FRACTION_H
