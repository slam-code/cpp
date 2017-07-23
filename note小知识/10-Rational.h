

#ifndef CPP_NOTE_RATIONAL_H
#define CPP_NOTE_RATIONAL_H

#include <iostream>

class Rational
{
public:
    Rational();

    Rational(int x);

    Rational(int x, int y);

    Rational(const Rational &r);

    const Rational &operator=(int x);

    const Rational &operator=(const Rational &r);

    virtual ~Rational();

    bool operator==(const Rational &other) const;

    friend const Rational operator+(const Rational &r1,
                                    const Rational &r2);

    friend const Rational operator-(const Rational &r1,
                                    const Rational &r2);

    friend const Rational operator*(const Rational &r1,
                                    const Rational &r2);

    friend const Rational operator/(const Rational &r1,
                                    const Rational &r2);

    friend std::ostream &operator<<(std::ostream &, const Rational &r);

    friend std::istream &operator>>(std::istream &, Rational &r);

private:
    static int gcd(int p, int q);

    int num; //numerator
    int div; //divisor
};

#endif //CPP_NOTE_RATIONAL_H
