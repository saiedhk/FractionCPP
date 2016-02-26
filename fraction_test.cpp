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
  Test program for 'Fraction' class.
*/

#include "fraction.h"

using std::cin;
using std::cout;
using std::endl;

using namespace shk_fraction;



int main( void )
{
   cout << "\n@@@@@@@@@@@@@@@@@@ Part 1 @@@@@@@@@@@@@@@@@@@@@@\n";

   Fraction a;
   Fraction b(1234567890);
   Fraction c(240,-1800);
   Fraction d(57654321012345678,-12345678987654321);

   cout << "1: a =" << a << "  b=" << b << "  c=" << c << " d=" << d << endl;

   try {
      //Fraction e(2924,0);
     Fraction e(2924,3);
      a = e;
      cout << "2: a =" << a << "  b=" << b << "  c=" << c << " d=" << d << " e=" << e << endl;
   }
   catch (ErrorCode err) {
      if (err==ErrorDivideByZero) {
         cout << "Error: zero in denominator!\n";
      }
   }


   try {
      Fraction e(2424,22);
      a = e;
      cout << "3: a =" << a << "  b=" << b << "  c=" << c << " d=" << d << " e=" << e << endl;
   }
   catch (ErrorCode err) {
      if (err==ErrorDivideByZero) {
         cout << "Error: zero in denominator!\n";
      }
   }


   cout << "4: d.num=" << d.numerator() << "    d.denom=" << d.denominator() << endl;
   cout << "5: d.sign=" << d.sign() << endl;
   cout << "6: d.realValue=" << d.realValue() << endl;
   cout << "7: d.integerPart=" << d.integerPart() << endl;
   cout << "8: d.fractionalPart=" << d.fractionalPart() << endl;

   a.set(7234,6880183);
   cout << "9: a =" << a << endl;

   a.setNum(-600891881);
   cout << "10: a =" << a << endl;

   a.setDenom(-85113);
   cout << "11: a =" << a << endl;

   a.negate();
   cout << "12: a =" << a << endl;
   a.negate();
   cout << "13: a =" << a << endl;

   cout << "14: a =" << a << "  quotient=" << a.properize() << endl;

   a.set(240,840);
   b.set(12,42);
   cout << "15: a =" << a << "  b=" << b;
   if (a==b)
      cout << "\ta = b";
   if (a<b)
      cout << "\ta < b";
   if (a<=b)
      cout << "\ta <= b";
   if (a>b)
      cout << "\ta > b";
   if (a>=b)
      cout << "\ta >= b";
   cout << endl;


   a.set(241,840);
   b.set(12,42);
   cout << "16: a =" << a << "  b=" << b;
   if (a==b)
      cout << "\ta = b";
   if (a<b)
      cout << "\ta < b";
   if (a<=b)
      cout << "\ta <= b";
   if (a>b)
      cout << "\ta > b";
   if (a>=b)
      cout << "\ta >= b";
   cout << endl;


   a.set(240,841);
   b.set(12,42);
   cout << "17: a =" << a << "  b=" << b;
   if (a==b)
      cout << "\ta = b";
   if (a<b)
      cout << "\ta < b";
   if (a<=b)
      cout << "\ta <= b";
   if (a>b)
      cout << "\ta > b";
   if (a>=b)
      cout << "\ta >= b";
   cout << endl;


   a.set(240,840);
   b.set(-12,42);
   cout << "18: a =" << a << "  b=" << b;
   if (a==b)
      cout << "\ta = b";
   if (a<b)
      cout << "\ta < b";
   if (a<=b)
      cout << "\ta <= b";
   if (a>b)
      cout << "\ta > b";
   if (a>=b)
      cout << "\ta >= b";
   cout << endl;


   a.set(9348939423911,291100020484011111);
   b.set(9348139423911,291100020484011112);
   cout << "19: a =" << a << "  b=" << b;
   try {
      if (a==b)
        cout << "\ta = b";
      if (a>b)
        cout << "\ta > b";
      if (a>=b)
        cout << "\ta >= b";
      if (a<b)
        cout << "\ta < b";
      if (a<=b)
        cout << "\ta <= b";
      cout << endl;
   }
   catch (ErrorCode e)
   {
      cout << "\nOverflow in compare!" << e << endl;
   }

   //------------
   a.set(12,96);
   real x = 0.125;
   cout << "20: a =" << a << "  x=" << x;
   if (a==x)
      cout << "\ta = x";
   if (a>x)
      cout << "\ta > x";
   if (a>=x)
      cout << "\ta >= x";
   if (a<x)
      cout << "\ta < x";
   if (a<=x)
      cout << "\ta <= x";
   cout << endl;


   a.set(93489394239,2911000204840);
   x = 0.0321159;
   cout << "21: a =" << a << "  x=" << x;
   if (a==x)
      cout << "\ta = x";
   if (a>x)
      cout << "\ta > x";
   if (a>=x)
      cout << "\ta >= x";
   if (a<x)
      cout << "\ta < x";
   if (a<=x)
      cout << "\ta <= x";
   cout << endl;


   a.set(93489394239,2911000204840);
   x = 0.0321165;
   cout << "22: a =" << a << "  x=" << x;
   if (a==x)
      cout << "\ta = x";
   if (a>x)
      cout << "\ta > x";
   if (a>=x)
      cout << "\ta >= x";
   if (a<x)
      cout << "\ta < x";
   if (a<=x)
      cout << "\ta <= x";
   cout << endl;


//--------
   a.set(12,96);
   x = 0.125;
   cout << "23: a =" << a << "  x=" << x;
   if (x==a)
      cout << "\tx = a";
   if (x>a)
      cout << "\tx > a";
   if (x>=a)
      cout << "\tx >= a";
   if (x<a)
      cout << "\tx < a";
   if (x<=a)
      cout << "\tx <= a";
   cout << endl;


   a.set(93489394239,2911000204840);
   x = 0.0321159;
   cout << "24: a =" << a << "  x=" << x;
   if (x==a)
      cout << "\tx = a";
   if (x>a)
      cout << "\tx > a";
   if (x>=a)
      cout << "\tx >= a";
   if (x<a)
      cout << "\tx < a";
   if (x<=a)
      cout << "\tx <= a";
   cout << endl;


   a.set(93489394239,2911000204840);
   x = 0.0321165;
   cout << "25: a =" << a << "  x=" << x;
   if (x==a)
      cout << "\tx = a";
   if (x>a)
      cout << "\tx > a";
   if (x>=a)
      cout << "\tx >= a";
   if (x<a)
      cout << "\tx < a";
   if (x<=a)
      cout << "\tx <= a";
   cout << endl;


//---------------------
   cout << "\n@@@@@@@@@@@@@@@@@@ Part 2 @@@@@@@@@@@@@@@@@@@@@@\n";

   int round = 1;

   while (1)
   {
      int sentinel;
      fint C1,C2;
      fint D1,D2;
      Fraction A,B,C,D;
      fint m, n;

      cout << "\n===============Round " << round << "================\n";

      cout << "Enter 1 to continue, -1 to finish testing => ";
      cin >> sentinel;
      if (sentinel < 0) break; // ends while loop, hence ends testing

      //-----------
      cout << "Enter two long long integers for fraction C => ";
      cin >> C1 >> C2;
      try
      {
         C.set(C1,C2);
         cout << "1: C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         if (e==ErrorDivideByZero) {
            cout << "You've set C denominator to zero! I set it to 1.\n";
            C.set(C1,1);
       }
      }


      //-----------
      cout << "Enter two long long integers for fraction D => ";
      cin >> D1 >> D2;
      try
      {
         D.set(D1,D2);
         cout << "2: D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         if (e==ErrorDivideByZero) {
            cout << "You've set D denominator to zero! I set it to 1.\n";
            D.set(D1,1);
       }
      }

      //------------
      cout << "Enter two integers m and n => ";
      cin >> m >> n;
      cout << "m =" << m << "\t  n=" << n << endl;
      cout << endl;

      //----------------------------------------
      //----- Now the action begins ------------
      //----------------------------------------

      cout << "\nACTION: A = C; B = D;\n";
      A = C; B = D;
      cout << "RESULT: A =" << A << "  B=" << B << "  C=" << C << "  D=" << D << endl;

      try
      {
         cout << "\nACTION: C = A + B\n";
         C = A + B;
         cout << "RESULT: A =" << A << "  B=" << B << "  C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = A - B\n";
         C = A - B;
         cout << "RESULT: A =" << A << "  B=" << B << "  C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = A * B\n";
         C = A * B;
         cout << "RESULT: A =" << A << "  B=" << B << "  C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = A / B\n";
         C = A / B;
         cout << "RESULT: A =" << A << "  B=" << B << "  C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = C + 1\n";
         C = C + 1;
         cout << "RESULT: C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = C - 1\n";
         C = C - 1;
         cout << "RESULT: C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = A + m\n";
         D = A + m;
         cout << "RESULT: A=" << A << "  m=" << m << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = m + A\n";
         D = m + A;
         cout << "RESULT: A=" << A << "  m=" << m << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = A * n\n";
         D = A * n;
         cout << "RESULT: A=" << A << "  n=" << n << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = n * A\n";
         D = n * A;
         cout << "RESULT: A=" << A << "  n=" << n << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = n / A\n";
         D = n / A;
         cout << "RESULT: A=" << A << "  n=" << n << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = A / n\n";
         D = A / n;
         cout << "RESULT: A=" << A << "  n=" << n << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: D = (A * C) - B/C  + n\n";
         D = (A * C) - B/C  + n;
         cout << "RESULT: A=" << A << " B=" << B << " C=" << C << " n=" << n << "  D=" << D << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = 1 / C\n";
         C = 1 / C;
         cout << "RESULT: C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = -C\n";
         C = -C;
         cout << "RESULT: C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }


      try
      {
         cout << "\nACTION: C = A - A; C = 1 / C\n";
         C = A - A; C = 1 / C;
         cout << "RESULT: C=" << C << endl;
      }
      catch (ErrorCode e)
      {
         switch (e) {
            case ErrorDivideByZero: cout << "ErrorDivideByZero: Action skipped!\n"; break;
            case ErrorAddOverflow: cout << "ErrorAddOverflow: Action skipped!\n"; break;
            case ErrorMultOverflow: cout << "ErrorMultOverflow: Action skipped!\n"; break;
            default: cout << "Invalid error code!!!\n";
         }
      }

      round++;

   } // while(1)


   return 0;
}
