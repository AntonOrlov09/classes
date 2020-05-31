#include "Rational.hpp"
#include <stdexcept>
#include <sstream>
using namespace std;

int NOD(int a,int b) {
    if (a<0) {
        a*=-1;
    }
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a+b;
}

Rational::Rational(int numerator, int denominator) :numerator_(numerator), denominator_(denominator) {
    if (denominator==0) {
        throw invalid_argument("denominator can not be 0");
    }
    if (denominator <0 ) {
        numerator_ *= -1;
        denominator_ *= -1;
    }
    int a = NOD(numerator_,denominator_);
    numerator_/=a;
    denominator_/=a;
}

int Rational::GetNumerator() const {
    return numerator_;
}

int Rational::GetDenominator() const {
    return denominator_;
}

Rational Rational::operator+(const Rational &rational) const {
    return Rational{rational.denominator_*numerator_+rational.numerator_*denominator_,rational.denominator_*denominator_};
}

Rational Rational::operator-(const Rational &rational) const {
    return Rational{rational.denominator_*numerator_-rational.numerator_*denominator_,rational.denominator_*denominator_};
}

Rational Rational::operator*(const Rational &rational) const {
    return Rational{numerator_*rational.numerator_,denominator_*rational.denominator_};
}

Rational Rational::operator/(const Rational &rational) const {
    return Rational{numerator_*rational.denominator_,denominator_*rational.numerator_};
}

bool Rational::operator==(const Rational &rational) const {
    return numerator_*rational.denominator_==denominator_*rational.numerator_;
}

bool Rational::operator>(const Rational &rational) const {
    return numerator_*rational.denominator_>denominator_*rational.numerator_;
}

bool Rational::operator<(const Rational &rational) const {
    return numerator_*rational.denominator_<denominator_*rational.numerator_;
}

bool Rational::operator>=(const Rational &rational) const {
    return numerator_*rational.denominator_>=denominator_*rational.numerator_;
}

bool Rational::operator<=(const Rational &rational) const {
    return numerator_*rational.denominator_<=denominator_*rational.numerator_;
}

bool Rational::operator!=(const Rational &rational) const {
    return numerator_*rational.denominator_!= denominator_*rational.numerator_;
}

Rational::operator double() {
    return static_cast<double>(GetNumerator()) / static_cast<double>(GetDenominator());
}

Rational::operator float() {
    return static_cast<float> (GetNumerator()) / static_cast<float> (GetDenominator());
}


ostream& operator << (ostream& stream,const Rational& rational) {
    stream << rational.GetNumerator() << "/" << rational.GetDenominator();
    return stream;
}
istream& operator >> (istream& stream, Rational& rational) {
    int num=0;
    int den=1;
    stream >> num;
    stream >> den;
    rational=Rational{num,den};
    return stream;
}







