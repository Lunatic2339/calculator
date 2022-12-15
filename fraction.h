#pragma once

#include <iostream>


class fraction
{
private:
	int numerator;
	int denominator;

	int gcd(int a, int b);
	int abs(int a);

	fraction(int n, int d, bool b);
public:
	fraction();
	fraction(int n);
	fraction(int n, int d);
	
	void set(int n, int d);

	fraction operator+(const fraction& fr);
	fraction operator+(int i);
	fraction& operator++();
	fraction operator++(int);
	fraction operator-(const fraction& fr);
	fraction operator-(int i);
	fraction operator-();
	fraction& operator--();
	fraction operator--(int);
	fraction operator*(const fraction& fr);
	fraction operator*(int i);
	fraction operator/(const fraction& fr);
	fraction operator/(int i);
	fraction& operator+=(const fraction& fr);
	fraction& operator-=(const fraction& fr);
	fraction& operator*=(const fraction& fr);
	fraction& operator/=(const fraction& fr);


	bool operator==(const fraction& fr);
	bool operator!=(const fraction& fr);
	bool operator>(const fraction& fr);
	bool operator<(const fraction& fr);
	bool operator>=(const fraction& fr);
	bool operator<=(const fraction& fr);

	friend std::ostream& operator<<(std::ostream& os, const fraction& fr);
	friend std::istream& operator>>(std::istream& is, fraction& fr);
};