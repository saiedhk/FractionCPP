# FractionCPP
C++ Fractional Arithmetic Library with Overflow Detection

This C++ library provides a 'Fraction' class that implements full precision arithmetic
operations on rational numbers with overflow detection. A rational number in mathematics is a
real number that can be represented as a fraction of two integers. We use 'fraction' and 'rational
number' synonymously.

In almost any useful algorithm involving a sequence of arithmetic operations on fractions, such 
summation of fractional series, the magnitude of nominators and denominators can grow very large 
very quickly. If such operations are not checked for overflow, the end result can be become
untrustworthy.

This C++ library addresses the above problem by implementing a 'Fraction' class, and checking for the 
overflow condition in arithmetic operations; If such conditions occur, an exception is thrown. The 
exception error alarms the calling function.

This package defines a class called 'Fraction' and overloads all of the useful arithmetic and 
comparison operators for this class. This allows the programmers to deal with Fraction objects 
(rational numbers) in the same manner as integers.
