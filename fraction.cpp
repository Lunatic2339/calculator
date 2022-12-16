#include "fraction.h"

#include <string>
#include <sstream>
#include <vector>

int fraction::gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int fraction::abs(int a)
{
	if (a < 0) a = -a;
	return a;
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
		numerator = 0;
		denominator = 1;
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

fraction& fraction::operator++()
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

fraction& fraction::operator--()
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
	try
	{
		if (fr.numerator == 0) throw 0;
		int x = gcd(denominator * fr.numerator, numerator * fr.denominator);
		return fraction((numerator * fr.denominator) / x, (denominator * fr.numerator) / x, true);
	}
	catch (int zero)
	{
		std::cout << "ERROR! fraction (" << numerator << ", " << denominator << ") divided by " << zero << std::endl;
		return *this;
	}
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
		return *this;
	}

}

fraction& fraction::operator+=(const fraction& fr)
{
	*this = *this + fr;
	return *this;
}

fraction& fraction::operator-=(const fraction& fr)
{
	*this = *this - fr;
	return *this;
}

fraction& fraction::operator*=(const fraction& fr)
{
	*this = *this * fr;
	return *this;
}

fraction& fraction::operator/=(const fraction& fr)
{
	*this = *this / fr;
	return *this;
}

fraction& fraction::operator+=(int i)
{
	*this = *this + i;
	return *this;
}

fraction& fraction::operator-=(int i)
{
	*this = *this - i;
	return *this;
}

fraction& fraction::operator*=(int i)
{
	*this = *this * i;
	return *this;
}

fraction& fraction::operator/=(int i)
{
	if (i != 0)
	{
		*this = *this / i;
	}
	else
	{
		std::cout << "ERROR! divide by zero!" << std::endl;
	}
	return *this;
}

fraction& fraction::operator=(int i)
{
	this->numerator = i;
	this->denominator = 1;
	return *this;
}

bool fraction::operator==(const fraction& fr)
{
	if (numerator / denominator == fr.numerator / fr.denominator) return true;
	return false;
}

bool fraction::operator!=(const fraction& fr)
{
	if (numerator / denominator != fr.numerator / fr.denominator) return true;
	return false;
}

bool fraction::operator>(const fraction& fr)
{
	if (numerator / denominator > fr.numerator / fr.denominator) return true;
	return false;
}

bool fraction::operator<(const fraction& fr)
{
	if (numerator / denominator < fr.numerator / fr.denominator) return true;
	return false;
}

bool fraction::operator>=(const fraction& fr)
{
	if (numerator / denominator >= fr.numerator / fr.denominator) return true;
	return false;
}

bool fraction::operator<=(const fraction& fr)
{
	if (numerator / denominator <= fr.numerator / fr.denominator) return true;
	return false;
}

bool fraction::operator==(int i)
{
	if (*this == fraction(i)) return true;
	return false;
}

bool fraction::operator!=(int i)
{
	if (*this != fraction(i)) return true;
	return false;
}

bool fraction::operator>(int i)
{
	if (*this > fraction(i)) return true;
	return false;
}

bool fraction::operator<(int i)
{
	if (*this < fraction(i)) return true;
	return false;
}

bool fraction::operator>=(int i)
{
	if (*this >= fraction(i)) return true;
	return false;
}

bool fraction::operator<=(int i)
{
	if (*this <= fraction(i)) return true;
	return false;
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
			os << abs(fr.numerator);
			if (fr.denominator != 1)
			{
				os << '/' << abs(fr.denominator);
			}
		}
	}
	return os;
}

std::istream& operator>>(std::istream& is, fraction& fr)
{

	std::string number;
	is >> number;
	fr.denominator = 1;
	std::vector<std::string> result;
	std::stringstream ss(number);
	std::string temp;
	while (std::getline(ss, temp, '/')) {
		result.push_back(temp);
	}
	std::stringstream ssInt(result[0]);
	ssInt >> fr.numerator;
	if (result.size() == 2)
	{
		std::stringstream ssInt2(result[1]);
		ssInt2 >> fr.denominator;
	}
	return is;
}
