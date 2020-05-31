#pragma once

#include <string>
#include <iostream>

class Rational {
private:
    int numerator_;
    int denominator_;
public:
    explicit Rational(int numerator=0,int denominator=1);
    int GetNumerator() const;
    int GetDenominator() const;
    Rational operator + (const Rational& rational) const;
    Rational operator - (const Rational& rational) const;
    Rational operator * (const Rational& rational) const;
    Rational operator / (const Rational& rational) const;
    bool operator == (const Rational& rational) const;
    bool operator > (const Rational& rational) const;
    bool operator < (const Rational& rational) const;
    bool operator >= (const Rational& rational) const;
    bool operator <= (const Rational& rational) const;
    bool operator != (const Rational& rational) const;
    explicit operator float();
    explicit operator double();

};
std::ostream& operator << (std::ostream& stream, const Rational& rhs);
std::istream& operator >> (std::istream& stream,  Rational& lhs);




