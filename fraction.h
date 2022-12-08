#pragma once


class fraction
{
private:
	int numerator;
	int denominator;

	int gcd(int a, int b);

	fraction(int n, int d, bool b);
public:
	fraction();
	fraction(int n);
	fraction(int n, int d);
	
	fraction operator+(const fraction& fr);
	fraction operator+(int i);
	fraction operator++();
	fraction operator++(int);
	fraction operator-(const fraction& fr);
	fraction operator-(int i);
	fraction operator-();
	fraction operator--();
	fraction operator--(int);
	fraction operator*(const fraction& fr);
	fraction operator*(int i);
	fraction operator/(const fraction& fr);
	fraction operator/(int i);
	fraction operator%(const fraction& fr);
	fraction operator%(int i);
	

};