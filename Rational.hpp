#pragma once

#include <string>

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
    double Cast_Double() const;
    float Cast_Float() const;
    std::string Print_Rational() const;
};



