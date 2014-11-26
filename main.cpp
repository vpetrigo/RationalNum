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

    double to_double() const {
        return double(numerator_) / denominator_;
    };

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

Rational operator+(Rational r1, Rational const& r2) {
  return r1 += r2;
}

Rational operator-(Rational r1, Rational const& r2) {
  return r1 -= r2;
}

Rational operator*(Rational r1, Rational const& r2) {
  return r1 *= r2;
}

Rational operator/(Rational r1, Rational const& r2) {
  return r1 /= r2;
}

bool operator==(Rational const& r1, Rational const& r2) {
    return ((r1 - r2).to_double() == 0) ? true : false;

}

bool operator!=(Rational const& r1, Rational const& r2) {
    return !(r1 == r2);
}

bool operator<(Rational const& r1, Rational const& r2) {
    return (r1 - r2).to_double() < 0 ? true : false;
}

bool operator>(Rational const& r1, Rational const& r2) {
    return (!(r1 < r2) && !(r1 == r2));
}

bool operator<=(Rational const& r1, Rational const& r2) {
    return (r1 == r2 || r1 < r2);
}

bool operator>=(Rational const& r1, Rational const& r2) {
    return (r1 == r2 || !(r1 < r2));
}

int main() {
    Rational a(3, 3);
    Rational b(1, 3);

    cout << a.to_double() << ' ' << b.to_double() << '\n';
    //Rational c = a + b;
    //c.print_result();
    if (a > 1)
        cout << '1';

    return 0;
}
