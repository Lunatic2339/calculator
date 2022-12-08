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
	int x = gcd(numerator * fr.denominator + fr.numerator * denominator, denominator * fr.denominator);
	return fraction((numerator * fr.denominator + fr.numerator * denominator)/x, (denominator * fr.denominator)/x, true);
}

fraction fraction::operator+(int i)
{
	return fraction(numerator + i * denominator, denominator, true);
}

fraction fraction::operator++()
{
	numerator += denominator;
	return *this;
}

fraction fraction::operator++(int)
{
	fraction result = *this;
	numerator += denominator;
	return result;
}

fraction fraction::operator-(const fraction& fr)
{
	int x = gcd(numerator * fr.denominator - fr.numerator * denominator, denominator * fr.denominator);
	return fraction((numerator * fr.denominator - fr.numerator * denominator)/x, (denominator * fr.denominator)/x, true);
}

fraction fraction::operator-(int i)
{
	return fraction(numerator - i * denominator, denominator, true);
}

fraction fraction::operator-()
{
	return fraction(-numerator, denominator, true);
}

fraction fraction::operator--()
{
	numerator -= denominator;
	return *this;
}

fraction fraction::operator--(int)
{
	fraction result = *this;
	numerator -= denominator;
	return result;
}

fraction fraction::operator*(const fraction& fr)
{
	int x = gcd(numerator * fr.numerator, denominator * fr.denominator);
	return fraction((numerator * fr.numerator)/x,(denominator * fr.denominator)/x,true);
}

fraction fraction::operator*(int i)
{
	int x = gcd(numerator * i, denominator);
	return fraction((numerator*i)/x, denominator/x, true);
}

fraction fraction::operator/(const fraction& fr)
{
	int x = (denominator * fr.numerator, numerator * fr.denominator);
	return fraction((denominator * fr.numerator)/x, (numerator * fr.denominator)/x, true);
}

fraction fraction::operator/(int i)
{
	int x = gcd(numerator, denominator * i);
	return fraction(numerator/x, (denominator*i)/x, true);
}


