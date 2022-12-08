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
	try 
	{
		if (d == 0) throw d;
		int x = gcd(n, d);
		numerator = n / x;
		denominator = d / x;
	}
	catch (int zero)
	{
		std::cout << "ERROR! fraction (" << n << ", " << d << ") divided by " << zero << std::endl;
	}
}

void fraction::set(int n, int d)
{
	try
	{
		if (d == 0) throw d;
		int x = gcd(n, d);
		numerator = n / x;
		denominator = d / x;
	}
	catch (int zero)
	{
		std::cout << "ERROR! fraction (" << n << ", " << d << ") divided by " << zero << std::endl;
	}
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
	try
	{
		if (i == 0) throw i;
		int x = gcd(numerator, denominator * i);
		return fraction(numerator / x, (denominator * i) / x, true);
	}
	catch (int zero)
	{
		std::cout << "ERROR! fraction (" << numerator << ", " << denominator << ") divided by " << zero << std::endl;
	}

}

std::ostream& operator<<(std::ostream& os, const fraction& fr)
{
	if (fr.denominator == 0)
	{
		os << "ERROR! fraction (" << fr.numerator << ", " << fr.denominator << ") divided by 0";
	}
	else
	{
		if (fr.numerator == 0)
		{
			os << 0;
		}
		else
		{
			if (fr.denominator * fr.numerator > 0) os << '+';
			else os << '-';
			if (fr.numerator > 0) os << fr.numerator;
			else os << -fr.numerator;
			if (fr.denominator != 1)
			{
				os << '/';
				if (fr.denominator > 0) os << fr.denominator;
				else os << -fr.denominator;
			}
		}
	}
	return os;
}

std::istream& operator>>(std::istream& is, fraction& fr)
{

	int n = 0, d = 0;
	is >> n >> d;
	if (d != 0)
	{
		fr.numerator = n;
		fr.denominator = d;
	}
	return is;
}
