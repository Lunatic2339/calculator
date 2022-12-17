#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
    void setNum(int n) { numerator = n; }
    void setDenom(int d) { denominator = d; }
    int num() { return numerator; }
    int denom() { return denominator; }


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
	fraction& operator+=(int i);
	fraction& operator-=(int i);
	fraction& operator*=(int i);
	fraction& operator/=(int i);
	fraction& operator=(int i);

	bool operator==(const fraction& fr);
	bool operator!=(const fraction& fr);
	bool operator>(const fraction& fr);
	bool operator<(const fraction& fr);
	bool operator>=(const fraction& fr);
	bool operator<=(const fraction& fr);
	bool operator==(int i);
	bool operator!=(int i);
	bool operator>(int i);
	bool operator<(int i);
	bool operator>=(int i);
	bool operator<=(int i);

	friend std::ostream& operator<<(std::ostream& os, const fraction& fr);
	friend std::istream& operator>>(std::istream& is, fraction& fr);


};


