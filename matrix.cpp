#include "matrix.h"

matrix::matrix()
	: m_v(VVF(2, VF(2))), row(1), col(1)
{
}

matrix::matrix(int row, int col, int num)
	: m_v(VVF(row+1, VF(col+1, fraction(num)))), row(row), col(col)
{
}

matrix::matrix(int row, int col, fraction fr)
	: m_v(VVF(row+1, VF(col+1, fr))), row(row), col(col)
{
}

matrix matrix::operator+(matrix m)
{
	matrix result = *this;
	if (row == m.row && col == m.col)
	{
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				result.m_v[i][j] = result.m_v[i][j] + m.m_v[i][j];
			}
		}
	}
	return result;
}

