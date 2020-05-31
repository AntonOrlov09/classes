#include <iostream>
#include "Rational.hpp"
#include <cmath>
using namespace std;


void test1() {
    Rational r = Rational();
    if (r.GetDenominator() == 1 && r.GetNumerator() == 0) {
        cout << "equal" << endl;
    }
}

void test2() {
    Rational r = Rational(1,-2);
    if (r.GetDenominator() == 2 && r.GetNumerator() == -1) {
        cout << "equal" << endl;
    }
}



void test3() {
    const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
    if (r == Rational(7, 12)) {
        cout << "equal" << endl;
    }
}
void test4() {
    const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
    if (r == Rational(2, 3)) {
        cout << "equal" << endl;
    }
}

void test5() {
    Rational r = Rational(1,3);
    if (abs(static_cast<double>(r)-0.333)<0.001) {
        cout << "equal" << endl;
    }
}

void test6() {
    Rational r = Rational(1,4);
    if (abs(static_cast<float>(r)-0.25)<0.001) {
        cout << "equal" << endl;
    }
}

void test7() {
    try{
        Rational r;
        cin >> r;
        cout << r;
    } catch(const invalid_argument& error){
        cout << "error" << endl;
    }
}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}