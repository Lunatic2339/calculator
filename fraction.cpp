#include "fraction.h"

int fraction::gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

fraction::fraction(int n, int d, bool b)
	: numerator(n), denominator(d)
{
}

fraction::fraction()
	: numerator(0), denominator(1)
{
}

fraction::fraction(int n)
	: numerator(n), denominator(1)
{
}

fraction::fraction(int n, int d)
{
	int x = gcd(n, d);
	numerator = n / x;
	denominator = d / x;
}

fraction fraction::operator+(const fraction& fr)
{
	int x = gcd(this->numerator * fr.denominator + fr.numerator * this->denominator, this->denominator * fr.denominator);
	return fraction((this->numerator * fr.denominator + fr.numerator * this->denominator)/x, (this->denominator * fr.denominator, true)/x);
}
