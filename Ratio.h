#pragma once
#include <iostream>

using namespace std;

enum Assignment_State
{
    EQUALS,
    NOT_EQUALS,
    BIGGER_THAN,
    SMALLER_THEN,
    UNDEFINED,
    FRACTION_TO_FLOAT_NUMBER,
    FRACTION_TO_INT_NUMBER,
    GET_NUMERATOR,
    GET_DENOMINATOR
    
};

class Ratio {
private:
    double numerator;
    double denominator;
    int IntPart = 0; //the integer part of number
    double OtherFractionNumerator = 0;
    double OtherFractionDenominator = 0; 
    int ComparisonSign = -1; //variable to compare
    
    Assignment_State Equal = Assignment_State::EQUALS;
    Assignment_State Not_Equal = Assignment_State::NOT_EQUALS;
    Assignment_State Bigger_Than = Assignment_State::BIGGER_THAN;
    Assignment_State Smaller_Than = Assignment_State::SMALLER_THEN;
    Assignment_State Undefined = Assignment_State::UNDEFINED;
    Assignment_State ToFloatNumber = Assignment_State::FRACTION_TO_FLOAT_NUMBER;
    Assignment_State ToIntNumber = Assignment_State::FRACTION_TO_INT_NUMBER;
    Assignment_State getNum = Assignment_State::GET_NUMERATOR;
    Assignment_State getDenom = Assignment_State::GET_DENOMINATOR;

    

public:

    Ratio() : numerator(1), denominator(1){} //default constructor
    Ratio(double n, double d)//initialization constructor
    {
        numerator = n;
        if (d == 0)
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
            exit(0); // will terminate the program if division by 0 is attempted
        }
        else
            denominator = d;
    }
    Ratio(double b)
    {
        numerator = b;
        denominator = 1;
        cout << "Is int num";
    }

    Ratio(double a, double n, double d)
    {
        IntPart = a;
        numerator = n;
        denominator = d;

    }

    Ratio(double n, double d, double OtherN, double OtherD, int State)
    {
        numerator = n;
        denominator = d;
        OtherFractionNumerator = OtherN;
        OtherFractionDenominator = OtherD;
        ComparisonSign = State;
    }

    Ratio(const Ratio &otherFraction)//copy constructor
    {
        this->numerator = otherFraction.numerator;
        this->denominator = otherFraction.denominator;
    }


////////////////////////////////////////////////////////////////////////
    const void SetNumerator(int ValueNumerator)
    {
        numerator = ValueNumerator;
    }
    const void SetDenominator(int ValueDenominator)
    {
        denominator = ValueDenominator;
    }

    const Ratio GetNumerator()const
    {
        return Ratio(numerator, denominator, 0, 0, GET_NUMERATOR);
       
    }

    const Ratio GetDenominator()const
    {
        return Ratio(numerator, denominator, 0, 0, GET_DENOMINATOR);

    }

/////////////////////////////////////////////////////////////////////////
    const Ratio FractionToFloatNumber()const//conversion to fraction to Floating-point
    {
        float number = numerator / denominator;
        float n = number;
        
        return Ratio(n, 0, 0, 0, ToFloatNumber);//conversion to fraction to int
    }
    const Ratio FractionToIntNumber()const
    {
        int number = numerator / denominator;
        int n = number;
        return Ratio(n, 0, 0, 0, ToIntNumber);
    }

    
    
/////////////////////////////////////////////////////////////////////////

    const Ratio ProperFraction() const
    {
        if (numerator < denominator)
        {

            
            int n1 = numerator;
            int d1 = denominator;

            return Ratio(n1, d1);
            

        }     
        else
        {
            int IntegerNumber = numerator / denominator;
            if (denominator == 1)
            {
                int n1 = IntegerNumber;
                return Ratio(n1);
            }
            else
            {
                int n1 = numerator - denominator;
                int d1 = denominator;
                int num = IntegerNumber;
                return Ratio(num, n1, d1);
            }
        }
        
        
    }

    
/////////////////////////////////////////////////////////////////////////

   const Ratio operator +(const Ratio &otherFraction) const
    {
        int n = numerator * otherFraction.denominator + otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);
        
        return Ratio(n1, d1);
    }
  

    const Ratio operator -(const Ratio& otherFraction) const
    {
        int n = numerator * otherFraction.denominator - otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);
    }

    const Ratio operator *(const Ratio& otherFraction)const
    {
        int n = numerator * otherFraction.numerator;
        int d = denominator * otherFraction.denominator;
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);
    }

    const Ratio operator /(const Ratio& otherFraction)const
    {
        int n = numerator * otherFraction.denominator;
        int d = denominator * otherFraction.numerator;
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);
    }
/////////////////////////////////////////////////////////

    const Ratio operator =(const Ratio& otherFraction)
    {

        numerator = otherFraction.numerator;
        denominator = otherFraction.denominator;
        int n1 = numerator;
        int d1 = denominator;

        return Ratio(n1, d1);
    }


    
    const Ratio operator +=(const Ratio& otherFraction)
    {
        const int n = numerator * otherFraction.denominator + otherFraction.numerator * denominator;
        const int d = denominator * otherFraction.denominator;

        int tempNum = numerator;
        int tempDen = denominator;

        
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);

        numerator = tempNum;
        denominator = tempDen;

    }

    const Ratio operator -=(const Ratio& otherFraction)
    {
        int n = numerator * otherFraction.denominator - otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
       
        int tempNum = numerator;
        int tempDen = denominator;

        numerator = n;
        denominator = d;

        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);

        numerator = tempNum;
        denominator = tempDen;
    }

    const Ratio operator *=(const Ratio& otherFraction)
    {
        int n = numerator * otherFraction.numerator;
        int d = denominator * otherFraction.denominator;

        int tempNum = numerator;
        int tempDen = denominator;

        numerator = n;
        denominator = d;
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);

        numerator = tempNum;
        denominator = tempDen;
    }

    const Ratio operator /=(const Ratio& otherFraction)
    {
        int n = numerator * otherFraction.denominator;
        int d = denominator * otherFraction.numerator;

        int tempNum = numerator;
        int tempDen = denominator;

        numerator = n;
        denominator = d;
        int n1 = n / gcd(n, d);
        int d1 = d / gcd(n, d);

        return Ratio(n1, d1);

        numerator = tempNum;
        denominator = tempDen;
    }
//////////////////////////////////////////////////////////

    const Ratio operator ^(const Ratio& otherFraction)const
    {
        if (otherFraction.denominator == 1)
        {
            if (otherFraction.numerator < 0)
            {
                int n = pow(denominator, (-1) * otherFraction.numerator);
                int d = pow(numerator, (-1) * otherFraction.numerator);
                
                return Ratio(n, d);
            }
            else
                if (otherFraction.numerator > 0)
                {
                    int n = pow(numerator, otherFraction.numerator);
                    int d = pow(denominator, otherFraction.numerator);
                   

                    return Ratio(n, d);
                }
                else
                {
                    return Ratio(1);
                }
        }
        else
        {
            int n = numerator;
            int d = denominator;
            int OtherFractionNumerator = otherFraction.numerator;
            int OtherFractionDenominator = otherFraction.denominator;
            return Ratio(n, d, OtherFractionNumerator, OtherFractionDenominator, Undefined);
            

        }
            
            


    }
 /////////////////////////////////////////////////////////


    const Ratio operator ==(const Ratio& otherFraction)const
    {
        
        if (numerator == otherFraction.numerator && denominator == otherFraction.denominator)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;
            
            return Ratio(n, d, OtherN, OtherD, Equal);
        }
        else
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;
            
            return Ratio(n, d, OtherN, OtherD, Not_Equal);
        }
            
    }

    const Ratio operator !=(const Ratio& otherFraction)const
    {
        if (numerator != otherFraction.numerator || denominator != otherFraction.denominator)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Not_Equal);
        }
        else
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Equal);
        }
    }

    const Ratio operator >(const Ratio& otherFraction)const
    {
        double n = numerator / denominator;
        double d = otherFraction.numerator / otherFraction.denominator;

        if (n > d)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Bigger_Than);
        }
        
        else
        if(n < d)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Smaller_Than);
        }
        else
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Equal);
        }

    }

    const Ratio operator <(const Ratio& otherFraction)const
    {
        double n = numerator / denominator;
        double d = otherFraction.numerator / otherFraction.denominator;

        if (n < d)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Smaller_Than);
        }
        else
        if(n > d)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Bigger_Than);
        }
        else
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Equal);
        }

    }

    const Ratio operator >=(const Ratio& otherFraction)const
    {
        double n = numerator / denominator;
        double d = otherFraction.numerator / otherFraction.denominator;

        if (n > d)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Bigger_Than);
        }

        else
            if (n < d)
            {
                int n = numerator;
                int d = denominator;
                int OtherN = otherFraction.numerator;
                int OtherD = otherFraction.denominator;

                return Ratio(n, d, OtherN, OtherD, Smaller_Than);
            }
            else
            {
                int n = numerator;
                int d = denominator;
                int OtherN = otherFraction.numerator;
                int OtherD = otherFraction.denominator;

                return Ratio(n, d, OtherN, OtherD, Equal);
            }

    }

    const Ratio operator <=(const Ratio& otherFraction)const
    {
        double n = numerator / denominator;
        double d = otherFraction.numerator / otherFraction.denominator;

        if (n > d)
        {
            int n = numerator;
            int d = denominator;
            int OtherN = otherFraction.numerator;
            int OtherD = otherFraction.denominator;

            return Ratio(n, d, OtherN, OtherD, Bigger_Than);
        }

        else
            if (n < d)
            {
                int n = numerator;
                int d = denominator;
                int OtherN = otherFraction.numerator;
                int OtherD = otherFraction.denominator;

                return Ratio(n, d, OtherN, OtherD, Smaller_Than);
            }
            else
            {
                int n = numerator;
                int d = denominator;
                int OtherN = otherFraction.numerator;
                int OtherD = otherFraction.denominator;

                return Ratio(n, d, OtherN, OtherD, Equal);
            }

    }
/////////////////////////////////////////////////////////

    

    void print() const
    {
        

        if (IntPart != 0)
            cout << "\n\n" << IntPart << " " << numerator << "/" << denominator;
        else if (ComparisonSign == Equal)
            cout << "\n\n" << numerator << "/" << denominator << " = " << OtherFractionNumerator << "/" << OtherFractionDenominator;
        else if (ComparisonSign == Not_Equal)
            cout << "\n\n" << numerator << "/" << denominator << " != " << OtherFractionNumerator << "/" << OtherFractionDenominator;
        else if (ComparisonSign == Bigger_Than)
            cout << "\n\n" << numerator << "/" << denominator << " > " << OtherFractionNumerator << "/" << OtherFractionDenominator;
        else if (ComparisonSign == Smaller_Than)
            cout << "\n\n" << numerator << "/" << denominator << " < " << OtherFractionNumerator << "/" << OtherFractionDenominator;
        else
            if (ComparisonSign == Undefined)
                cout << "\n\n" << "another number is not interger";
        else
            if (ComparisonSign == ToFloatNumber)
                cout << "\n\n" << numerator;
        else
            if (ComparisonSign == ToIntNumber)
                cout << "\n\n" << numerator;
        if (ComparisonSign == GET_NUMERATOR)
            cout << "\n\n" << numerator;
        else
            if (ComparisonSign == GET_DENOMINATOR)
                cout << "\n\n" << denominator;
        else
            cout << "\n\n" << numerator << "/" << denominator;
    }

    const int gcd(int n, int d) const 
    {
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }

};