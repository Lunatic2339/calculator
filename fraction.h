#pragma once

#include <vector>
#include <iostream>


inline int gcd(int a, int b) // 최대공약수
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}
inline int abs_val(int a)
{
	if (a >= 0) return a;
	else return -a;
}
inline std::vector<int> intFactor(int t) // 소인수분해 - 벡터에 소인수저장
{
	int n = t;
	std::vector<int> factor;
	for (int i = 2; i * i <= t; ++i)
	{
		while (n % i == 0)
		{
			n /= i;
			factor.push_back(i);
		}
	}
	if (n != 1)
	{
		factor.push_back(n);
	}
	return factor;
}



class fraction
{
private:
	class number
	{
	public:
		int denom;
		int num;
		unsigned int root;
		short sign;
		number();
		number(int x, int y, unsigned int z = 1);

		number operator+(number n);
		number operator-(number n);
		number operator-();

	};
	std::vector<number> nArr;
public:
	fraction();
	fraction(int denominator, int numerator);
	fraction(int denominator, int numerator, int root);
	fraction(const fraction& other);

	
	void Print()
	{
		for (number n : nArr)
		{
			if (n.num == 0 || n.root == 0) std::cout << 0;
			else
			{
				if (n.sign == 1) std::cout << '+';
				else if (n.sign == -1) std::cout << '-';
				if (n.denom == 1) std::cout << n.num;
				else std::cout << n.num << '/' << n.denom;
				if (n.root != 1) std::cout << "(root)" << n.root;
			}
		}
		std::cout << std::endl;
	}



	fraction operator+(const fraction& frac);
	fraction operator+(int n);
	fraction operator-(const fraction& frac);
	fraction operator-(int n);
	fraction operator*(const fraction& frac);
	fraction operator/(const fraction& frac);

};