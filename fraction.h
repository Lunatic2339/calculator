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

    friend std::vector<std::string> fraction_to_string(std::vector<fraction> f_v)
    {
        std::vector<std::string> s_v(f_v.size());
        for(int i = 0; i < f_v.size(); ++i)
        {
            if(f_v[i].denominator * f_v[i].numerator < 0) s_v[i].push_back('-');
            s_v[i] = s_v[i] + std::to_string(f_v[i].numerator);
            if(f_v[i].denominator != 1)
            {
                s_v[i].push_back('/');
                s_v[i] = s_v[i] + std::to_string(f_v[i].denominator);
            }
        }
        return s_v;
    }
};
