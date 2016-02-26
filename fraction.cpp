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


#include "fraction.h"
#include "utility.h"

#include <assert.h>

namespace shk_fraction
{

//------------------------------------------------
// Constructors
//------------------------------------------------
Fraction::Fraction(void) : num(0), denom(1) {}

Fraction::Fraction(fint a) : num(a), denom(1) {}

Fraction::Fraction(fint a, fint b) : num(a), denom(b) { reduce(); }

//------------------------------------------------
// Accessors
//------------------------------------------------

fint Fraction::numerator() const
{
   return num;
}


fint Fraction::denominator() const
{
   return denom;
}


int Fraction::sign(void) const
{
   return (num>=0) ? 1 : -1;
}


double Fraction::realValue(void) const
{
   return static_cast<double>(num)/denom;
}


fint Fraction::integerPart(void) const
{
   return (num / denom);
}


double Fraction::fractionalPart(void) const
{
   return static_cast<double>(num)/denom - (num/denom);
}


//------------------------------------------------
// Mutators
//------------------------------------------------

// set numerator and denominator
void Fraction::set(fint a, fint b)
{
   num = a;
   denom = b;
   reduce();
}


// set numerator
void Fraction::setNum(fint a)
{
   num = a;
   reduce();
}


// set denominator
void Fraction::setDenom(fint b)
{
   denom = b;
   reduce();
}


// change sign of fraction
void Fraction::negate(void)
{
   num = -num;
}


// converts fraction to a proper fraction (in which num<denom)
// returns the integer part
fint Fraction::properize(void)
{
   fint quotient = num / denom;
   fint remainder = num % denom;
   num = remainder;
   return quotient;
}


//------------------------------------------------
// Operators
//------------------------------------------------

// equality checker
bool operator==(const Fraction& left, const Fraction& right)
{
   return left.compare(right)==0;
}


// inequality checker
bool operator!=(const Fraction& left, const Fraction& right)
{
   return left.compare(right)!=0;
}


// greater checker
bool operator>(const Fraction& left, const Fraction& right)
{
   return left.compare(right) > 0;
}


// less checker
bool operator<(const Fraction& left, const Fraction& right)
{
   return left.compare(right) < 0;
}


// equal or greater checker
bool operator>=(const Fraction& left, const Fraction& right)
{
   return left.compare(right) >= 0;
}


// equal or less checker
bool operator<=(const Fraction& left, const Fraction& right)
{
   return left.compare(right) <= 0;
}


//------------------------
// equality checker
bool operator==(real left, const Fraction& right)
{
   return left == right.realValue();
}


// inequality checker
bool operator!=(real left, const Fraction& right)
{
   return left != right.realValue();
}


// greater checker
bool operator>(real left, const Fraction& right)
{
   return left > right.realValue();
}


// less checker
bool operator<(real left, const Fraction& right)
{
   return left < right.realValue();
}


// equal or greater checker
bool operator>=(real left, const Fraction& right)
{
   return left >= right.realValue();
}


// equal or less checker
bool operator<=(real left, const Fraction& right)
{
   return left <= right.realValue();
}


//-----------------------
// equality checker
bool operator==(const Fraction& left, real right)
{
   return left.realValue() == right;
}


// inequality checker
bool operator!=(const Fraction& left, real right)
{
   return left.realValue() != right;
}


// greater checker
bool operator>(const Fraction& left, real right)
{
   return left.realValue() > right;
}


// less checker
bool operator<(const Fraction& left, real right)
{
   return left.realValue() < right;
}


// equal or greater checker
bool operator>=(const Fraction& left, real right)
{
   return left.realValue() >= right;
}


// equal or less checker
bool operator<=(const Fraction& left, real right)
{
   return left.realValue() <= right;
}


//----------------------------
// addition
Fraction operator+(const Fraction& left, const Fraction& right)
{
   fint temp1 = left.num * right.denom;
   fint temp2 = left.denom * right.num;
   fint a = temp1 + temp2;
   fint b = left.denom * right.denom;

   #ifdef OVFCHECK
   CheckMultOvf(left.num, right.denom, temp1);
   CheckMultOvf(left.denom, right.num, temp2);
   CheckAddOvf(temp1,temp2,a);
   CheckMultOvf(left.denom, right.denom, b);
   #endif

   return Fraction(a,b);
}


// subtraction
Fraction operator-(const Fraction& left, const Fraction& right)
{
   fint temp1 = left.num * right.denom;
   fint temp2 = left.denom * right.num;
   fint a = temp1 - temp2;
   fint b =  left.denom * right.denom;

   #ifdef OVFCHECK
   CheckMultOvf(left.num, right.denom, temp1);
   CheckMultOvf(left.denom, right.num, temp2);
   CheckAddOvf(temp1, -temp2, a);
   CheckMultOvf(left.denom, right.denom, b);
   #endif

   return Fraction(a,b);
}


// Multiplication
Fraction operator*(const Fraction& left, const Fraction& right)
{
   fint temp = gcd( abs(left.num), abs(right.denom) );
   fint a1 = left.num / temp;
   fint b1 = right.denom / temp;
   temp = gcd( abs(left.denom), abs(right.num) );
   fint a2 = right.num / temp;
   fint b2 = left.denom / temp;

   fint temp1 = a1 * a2;
   fint temp2 = b1 * b2;
   #ifdef OVFCHECK
   CheckMultOvf(a1, a2, temp1);
   CheckMultOvf(b1, b2, temp2);
   #endif

   return Fraction(temp1, temp2);
}


// Division
Fraction operator/(const Fraction& left, const Fraction& right)
{
   if (right.num==0) throw ErrorDivideByZero;
   fint temp = gcd( abs(left.num), abs(right.num) );
   fint a1 = left.num / temp;
   fint b1 = right.num / temp;
   temp = gcd( abs( left.denom), abs(right.denom) );
   fint a2 = right.denom / temp;
   fint b2 = left.denom / temp;

   fint temp1 = a1 * a2;
   fint temp2 = b1 * b2;
   #ifdef OVFCHECK
   CheckMultOvf(a1, a2, temp1);
   CheckMultOvf(b1, b2, temp2);
   #endif

   return Fraction((a1 * a2), (b1 * b2));
}


//----------------------
Fraction operator+(const Fraction& left, fint iright)
{
   Fraction right(iright);
   return left + right;
}


Fraction operator-(const Fraction& left, fint iright)
{
   Fraction right(iright);
   return left - right;
}


Fraction operator*(const Fraction& left, fint iright)
{
   Fraction right(iright);
   return left * right;
}


Fraction operator/(const Fraction& left, fint iright)
{
   Fraction right(iright);
   return left / right;
}


//----------------------
Fraction operator+(fint ileft, const Fraction& right)
{
   Fraction left(ileft);
   return left + right;
}


Fraction operator-(fint ileft, const Fraction& right)
{
   Fraction left(ileft);
   return left - right;
}


Fraction operator*(fint ileft, const Fraction& right)
{
   Fraction left(ileft);
   return left * right;
}


Fraction operator/(fint ileft, const Fraction& right)
{
   Fraction left(ileft);
   return left / right;
}

Fraction operator-(const Fraction& f)
{
    Fraction result( -f.numerator(), f.denominator() );
    return result;
}


//----------------------
ostream& operator<<(ostream &output, const Fraction& right)
{
    output << "(" << right.numerator() << "/" << right.denominator() << ")";
    return output;
}



//----------------------
// Private Functions

// reduce fraction to simplest form
void Fraction::reduce(void)
{
   if (denom==0) throw ErrorDivideByZero;
   int sign = 1;
   if (num<0) { sign = -sign; num = -num; }
   if (denom<0) { sign = -sign; denom = -denom; }
   fint temp = gcd(num, denom);
   if (sign == -1) num = -num;
   num = num / temp;
   denom = denom / temp;
}


// compare two fractions
fint Fraction::compare(Fraction r) const
{
   fint temp1 = num * r.denom;
   fint temp2 = denom * r.num;
   fint temp = temp1 - temp2;

   #ifdef OVFCHECK
   CheckMultOvf(num, r.denom, temp1);
   CheckMultOvf(denom, r.num, temp2);
   CheckAddOvf(temp1,-temp2,temp);
   #endif

   return temp;
}



} // namespace saied_hk
