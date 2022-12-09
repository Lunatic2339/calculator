#include "matrix.h"

matrix::matrix()
	: m_v(VVF(1, VF(1))), row(1), col(1)
{
}

matrix::matrix(int row, int col, int num)
	: m_v(VVF(row, VF(col, fraction(num)))), row(row), col(col)
{
}

matrix::matrix(int row, int col, fraction fr)
	: m_v(VVF(row, VF(col, fr))), row(row), col(col)
{
}

matrix::matrix(int rowcol, int n, bool idt)
	: m_v(VVF(rowcol, VF(rowcol, fraction(0)))), row(rowcol), col(rowcol)
{
	for (int i = 0; i < rowcol; ++i)
	{
		m_v[i][i] = fraction(n);
	}
}

matrix::matrix(int rowcol, fraction fr, bool idt)
	: m_v(VVF(rowcol, VF(rowcol, fraction(0)))), row(rowcol), col(rowcol)
{
	for (int i = 0; i < rowcol; ++i)
	{
		m_v[i][i] = fr;
	}
}

matrix matrix::power(int n)
{
	matrix result = *this;
	for (int i = 0; i < n; ++i)
	{
		result = result * result;
	}
	return result;
}

matrix matrix::tr()
{
	matrix result(col, row);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			result.m_v[j][i] = this->m_v[i][j];
		}
	}
	return result;
}

matrix matrix::sub(int r, int c)
{
	matrix result(row - 1, col - 1, 0);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (i != r-1 || j != c-1)
			{
				result.m_v[i][j] = m_v[i][j];
			}
		}
	}
	return result;
}

matrix matrix::adj()
{
	try
	{
		if (row != col) throw 0;
		matrix result(row, col);
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				result.m_v[i][j] = cof(j+1,i+1);
			}
		}
	}
	catch (int zero)
	{
		std::cout << "Not Square Matrix!" << std::endl;
	}
}

matrix matrix::inverse()
{
	try
	{
		if (det() == fraction(0)) throw 0;
		matrix result = adj() / det();
		return result;
	}
	catch (int zero)
	{
		std::cout << "divide by zero" << std::endl;
		return *this;
	}
}


fraction matrix::det()
{
	try
	{
		if (row != col) throw 0;
		else
		{
			if (row == 1) return m_v[1][1];
			else if (row == 2)
			{
				return (m_v[0][0] * m_v[1][1] - m_v[0][1] * m_v[1][0]);
			}
			else if (row > 2)
			{
				fraction result(0);
				for (int i = 0; i < col; ++i)
				{
					
					if (i % 2 == 0)
					{
						result = result + m_v[0][i] * this->sub(0, col).det();
					}
					else
					{
						result = result - m_v[0][i] * this->sub(0, col).det();
					}
				}
				return result;
			}
		}
	}
	catch (int zero)
	{
		std::cout << "Not Square Matrix!" << std::endl;
	}
}

fraction matrix::cof(int r, int c)
{
	if (r + c % 2 == 0) 
	{
		return sub(r, c).det();
	}
	else
	{
		return -sub(r, c).det();
	}
}

matrix matrix::operator+(matrix m)
{
	matrix result = *this;
	try
	{
		if (row != m.row || col != m.col) throw 0;
		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					result.m_v[i][j] = result.m_v[i][j] + m.m_v[i][j];
				}
			}
		}
		
	}
	catch (int zero)
	{
		std::cout << "Not Same Matrix Size : (" << row << 'x' << col << ')' << std::endl;
	}
	return result;
}

matrix matrix::operator+(int n)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f + n;
		}
	}
	return result;
}

matrix matrix::operator+(fraction fr)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f + fr;
		}
	}
	return result;
}

matrix matrix::operator-(matrix m)
{
	matrix result = *this;
	try
	{
		if (row != m.row || col != m.col) throw 0;
		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					result.m_v[i][j] = result.m_v[i][j] - m.m_v[i][j];
				}
			}
		}

	}
	catch (int zero)
	{
		std::cout << "Not Same Matrix Size : (" << row << 'x' << col << ')' << std::endl;
	}
	return result;
}

matrix matrix::operator-(int n)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f - n;
		}
	}
	return result;
}

matrix matrix::operator-(fraction fr)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f - fr;
		}
	}
	return result;
}

matrix matrix::operator*(matrix m)
{
	matrix result = *this;
	try
	{
		if (col != m.row) throw 0;
		else
		{
			result.m_v = VVF(row, VF(m.col));
			fraction fr;
			for (int i = 0; i < row; ++i)
			{

				for (int j = 0; j < m.col; ++j)
				{
					fr.set(0, 1);
					for (int a = 0; a < col; ++a)
					{
						fr = fr + m_v[i][a]*m.m_v[a][j];
					}
					result.m_v[i][j] = fr;
				}
			}
		}

	}
	catch (int zero)
	{
		std::cout << "error" << std::endl;
	}
	return result;
}

matrix matrix::operator*(int k)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f * k;
		}
	}
	return result;
}

matrix matrix::operator*(fraction fr)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f * fr;
		}
	}
	return result;
}

matrix matrix::operator/(int k)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f / k;
		}
	}
	return result;
}

matrix matrix::operator/(fraction fr)
{
	matrix result = *this;
	for (VF& vf : result.m_v)
	{
		for (fraction& f : vf)
		{
			f = f / fr;
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const matrix& m)
{
	for (VF vf : m.m_v)
	{
		for (fraction f : vf)
		{
			os << f << ' ';
		}
		os << std::endl;
	}
	return os;
}

std::ostream& operator>>(std::istream& is, matrix& m)
{
	for (VF& vf : m.m_v)
	{
		for (fraction& f : vf)
		{
			is >> f;
		}
	}
}
