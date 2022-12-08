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
			for (int i = 0; i < row; ++i)
			{
				int x = 
				for (int j = 0; j < m.col; ++j)
				{
					int x = 0;
					for (int k = 0)
					result.m_v[i][j];
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


