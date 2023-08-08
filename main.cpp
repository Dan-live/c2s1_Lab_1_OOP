#include "Ratio.h"

using namespace std;

//    1)	Implement mathematical operations of addition, subtraction, multiplication
//    and dividing numbers(both among themselvesand with whole numbers).
//    For this you can use( + - * / ) 
//    for instance "(a + b).print".
//    
//    2)	Compare numbers for equalityand order
//    For this you can use ( == != > < >= <= )  
//    for instance "(a == b).print".
//    
//    3)	Raise fractions to a integer power.
//    For this you can use( ^ )  
//    for instance "(a ^ b).print".
//    
//    4)	Implement access to the numeratorand denominator(reading and
//    modification).
//    For this you can use( SetNumerator, SetDenominator, GetNumerator, GetDenominator)  
//    for instance "a.SetDenominator(1)  a.GetDenominator() ".
//    
//    5)	Implement the possibility of obtaining integer and fractional part of a fraction.
//    For this you can use(ProperFraction)
//    for instance "a.ProperFraction().print() ".
//    
//    6)	Implement the possibility of converting a fraction to a float number
//    , as well as an integer.
//    For this you can use(FractionToFloatNumber, FractionToIntNumber)
//    for instance "a.FractionToFloatNumber().print()  a.FractionToIntNumber().print() ".
//    
//    7)Implement assignment operations.
//    For this you can use( = += -= *= /= )
//    for instance 
//    "(a = b).print;
//     (a += b).print;
//     (a -= b).print;
//     (a *= b).print;
//     (a -= b).print;
//     (a /= b).print; ".
//    
//    8)	Implement a check whether a fraction is an integer.
//    if the fraction is not integer number, a corresponding notification will be displayed.


int main()
{

	Ratio a(3, 2);
	Ratio b(1, 5);
	
	/*(a = b).print();
	(a += b).print();*/
	a.GetNumerator().print();
	a.GetDenominator().print();
	return 0;
}