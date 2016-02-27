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

PROJECT DESCRIPTION
-------------------

This C++ library provides a 'Fraction' class that implements full precision arithmetic
operations on rational numbers with overflow detection. A rational number in mathematics is a
real number that can be represented as a fraction of two integers. We use 'fraction' and 'rational
number' synonymously.

In almost any useful algorithm involving a sequence of arithmetic operations on fractions (such as 
summation of fractional series) the magnitude of nominators and denominators can grow very large 
very quickly. If such operations are not checked for overflow, the end result can be become
untrustworthy.

This C++ library addresses the above problem by providing a 'Fraction' class that checks for the 
overflow condition in arithmetic operations; Should such condition occurs, an exception is thrown 
alarming the calling function. It also overloads all of the useful arithmetic and comparison 
operators for this class, allowing the programmer to deal with Fractions (rational numbers) 
in the same manner as integers.

The package defines a namespace called shk_fraction and consists of the following files:

	o typedefs.h : This file contains 'typedef' statements defining 'fint' (the
	integer type) and 'real' (the floating-point type) that are used in this
	package.
	o utility.h : This file contains the utility functions that are used in
	implementing the 'Fraction' class.
	o fraction.h : This is the header file for 'Fraction' class. All class
	methods are documented here in Javadoc style.
	o fraction.cpp : This file contain the implementation of 'Fraction' class.
	o fraction_test.cpp : This is a test program to test the 'Fraction' class.
	o fraction_sample_app1.cpp : This is a sample application for 'Fraction'
	class. It computes the continued fraction of a given rational number.
	o fraction_sample_app2.cpp : This is a sample application for 'Fraction'
	class. It computes a finite summation of a series of fractions.

The above files contain plenty of comments. The API for this library is all
documented in fraction.h file.

Please forward suggestions, bug reports and comments to the author of this library. 

Thank you.
