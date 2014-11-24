#include <iostream>

using namespace std;

struct Rational
{
    Rational(int numerator = 0, unsigned denominator = 1) : numerator_(numerator),
                                                        denominator_(denominator) {};

    void print_result(void) {
        int t_num = getNumerator_();
        if (!t_num)
            cout << "0\n";
        else
            cout << t_num << '/' << getDenominator_() << '\n';
    }

    int getNumerator_() const {
        return numerator_;
    }

    unsigned int getDenominator_() const {
        return denominator_;
    }

    void add(Rational const rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    };
    void sub(Rational const rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    };
    void mul(Rational const rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    };
    void div(Rational const rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    };

    void neg() {
        numerator_ = -numerator_;
    };
    void inv();
    double to_double() const;

    Rational& operator+=(Rational const &rational) {
        (*this).add(rational);

        return (*this);
    };
    Rational& operator-=(Rational const &rational) {
        (*this).sub(rational);

        return (*this);
    };
    Rational& operator*=(Rational const &rational) {
        (*this).mul(rational);

        return (*this);
    };
    Rational& operator/=(Rational const &rational) {
        (*this).div(rational);

        return (*this);
    };

    Rational operator-() {
        (*this).neg();

        return (*this);
    };
    Rational operator+() {
        return (*this);
    };

private:
    int numerator_;
    unsigned denominator_;
};

int main() {
    Rational a(6, 2);
    Rational b(3, 2);


    a -= b;
    a.print_result();
    return 0;
}