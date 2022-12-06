#include "fraction.h"

// fraction class default constructor
fraction::fraction()
{
	nArr.push_back(number(0,0,0));
}

//  fraction class custom constructor 1
fraction::fraction(int denominator, int numerator)
{
	nArr.push_back(number(denominator, numerator, 1));
}

//  fraction class custom constructor 2
fraction::fraction(int denominator, int numerator, int root)
{
	nArr.push_back(number(denominator, numerator, root));
}

//  fraction class copy constructor
fraction::fraction(const fraction& other)
{
	nArr = other.nArr;
}



// fraction class '+' operator overloading
fraction fraction::operator+(const fraction& frac)
{
	fraction result = *this;
	for (number n : frac.nArr)
	{
		int con = 0;
		for (number& m : result.nArr)
		{
			if (n.root == m.root) m = m + n;
			else ++con;
		}
		if (con == result.nArr.size()) result.nArr.push_back(n);
	}
	return result;
}

fraction fraction::operator-(const fraction& frac)
{
	fraction result = *this;
	for (number n : frac.nArr)
	{
		int con = 0;
		for (number& m : result.nArr)
		{
			if (n.root == m.root) m = m - n;
			else ++con;
		}
		if (con == result.nArr.size()) result.nArr.push_back(-n);
	}
	return result;
}






















// number inner class default constrctor
fraction::number::number()
	: denom(0), num(0), root(0)
{
	sign = 1;
}

// number inner class custom constrctor
fraction::number::number(int x, int y, unsigned int z)
	: denom(abs_val(x)), num(abs_val(y)), root(z)
{
	if (x * y > 0) sign = 1;
	else if (x * y < 0) sign = -1;
}

// number inner class '+' operator overloading
fraction::number fraction::number::operator+(number n)
{
	if (this->root == n.root)
	{
		if (this->sign == 1 && n.sign == 1)
		{
			int x = gcd(this->denom * n.denom, this->num * n.denom + n.num * this->denom);
			number result((this->denom * n.denom) / x, (this->num * n.denom + n.num * this->denom) / x, this->root);
			return result;
		}
		else if (this->sign == 1 && n.sign == -1)
		{
			int x = gcd(this->denom * n.denom, this->num * n.denom - n.num * this->denom);
			number result((this->denom * n.denom) / x, (this->num * n.denom - n.num * this->denom) / x, this->root);
			return result;
		}
		else if (this->sign == -1 && n.sign == 1)
		{
			int x = gcd(this->denom * n.denom, n.num * this->denom - this->num * n.denom);
			number result((this->denom * n.denom) / x, (n.num * this->denom - this->num * n.denom) / x, this->root);
			return result;
		}
		else if (this->sign == -1 && n.sign == -1)
		{
			int x = gcd(this->denom * n.denom, -this->num * n.denom - n.num * this->denom);
			number result((this->denom * n.denom) / x, (-this->num * n.denom - n.num * this->denom) / x, this->root);
			return result;
		}
	}

	else throw "not same root value";
}

fraction::number fraction::number::operator-(number n)
{
	if (this->root == n.root)
	{
		int x = gcd(this->denom * n.denom, this->num * n.denom - n.num * this->denom);
		number result((this->denom * n.denom) / x, (this->num * n.denom + n.num * this->denom) / x, this->root);
	}
	else throw "not same root value";
}

fraction::number fraction::number::operator-()
{
	return number();
}

