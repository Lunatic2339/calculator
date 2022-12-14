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

matrix::matrix(VF vf, int row, int col)
	: m_v(VVF(row, VF(col))), row(row), col(col)
{
	
	if (row * col != vf.size()) std::cout << "invalid vector size" << std::endl;
	else
	{
		int idx = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
                m_v[i][j] = vf[idx];
                idx++;
			}
		}
	}
}

void matrix::set_rowcol(int r, int c, int num)
{
	row = r;
	col = c;
	m_v.resize(row);
	for (VF& vf : m_v)
	{
		vf.resize(col);
		for (fraction& f : vf)
		{
			f = num;
		}
	}
}

void matrix::set_by_vector(VF vf, int r, int c)
{
	m_v.resize(r);
	for (VF& v : m_v)
	{
		v.resize(c);
	}
	if (r * c != vf.size())
	{
		std::cout << "invalid vector size" << std::endl;
		return;
	}
	else
	{
		int idx = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				m_v[i][j] = vf[idx++];
			}
		}
	}
}

VF matrix::matrix_to_vector()
{
	VF v_f;
	for (VF vf : m_v)
	{
		for (fraction f : vf)
		{
			v_f.push_back(f);
		}
	}
	return v_f;
}

matrix matrix::power(int n)
{
	matrix result = *this;
	for (int i = 1; i < n; ++i)
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
	int ii = 0;
	for (int i = 0; i < row; ++i)
	{
		int jj = 0;
		for (int j = 0; j < col; ++j)
		{
			
			if (i == (r - 1) || j == (c - 1))
			{

			}
			else 
			{
				result.m_v[ii][jj] = m_v[i][j];
			}
			if (j != c - 1) jj++;
		}
		if (i != r - 1) ii++;
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
		return result;
	}
	catch (int zero)
	{
		std::cout << "Not Square Matrix!" << std::endl;
		return *this;
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

PMM matrix::LUdecompose()
{
	try 
	{
		if (row != col) throw 0;
		matrix lower(row, 1, true);
		matrix upper(row, col);
		fraction sigma(0);
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i > j)  // lower
				{
					sigma = 0;
					for (int k = 0; k < j - 1; ++k)
					{
						sigma = sigma + lower.m_v[i][k] * upper.m_v[k][j];
					}
					lower.m_v[i][j] = (m_v[i][j] - sigma) / upper.m_v[j][j];
				}
				else
				{
					sigma = 0;
					for (int k = 0; k < i - 1; ++k)
					{
						sigma = sigma + lower.m_v[i][k] * upper.m_v[k][i];
					}
					upper.m_v[i][j] = m_v[i][j] - sigma;
				}
			}
		}

		return PMM(lower, upper);
	}
	catch (int zero)
	{
		std::cout << "Not Square Matrix!" << std::endl;
		return PMM(*this, *this);
	}

}


fraction matrix::det()
{
	try
	{
		if (row != col) throw 0;
		else
		{
			if (row == 1) return m_v[0][0];
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
						result = result + m_v[0][i] * (this->sub(1, i+1).det());
					}
					else
					{
						result = result - m_v[0][i] * (this->sub(1, i+1).det());
					}
				}
				return result;
			}
		}
	}
	catch (int zero)
	{
		std::cout << "Not Square Matrix!" << std::endl;
        return 0;
	}
}

fraction matrix::cof(int r, int c)
{
	if ((r + c) % 2 == 0) 
	{
		return sub(r, c).det();
	}
	else
	{
		return -(sub(r, c).det());
	}
}

matrix matrix::echelon() {
	matrix result(col, row);
	matrix result2(col, row);
	int new_m1 = 0;
	int new_m2 = 0;

	fraction div = 0;
	
	
	for (int i = 0; i < col; i++) {
		if (m_v[i][0] != 0 && new_m1 < col) {
			for (int j = 0; j < row; j++) {
				result.m_v[new_m1][j] = m_v[i][j];
			}
			new_m1++;
		}
	}

	if (new_m1 < col) {
		for (int i = 0; i < col; i++) {
			if (m_v[i][0] == 0 && m_v[i][1] != 0 && new_m1 < col) {
				for (int j = 0; j < row; j++) {
					result.m_v[new_m1][j] = m_v[i][j];
				}
				new_m1++;
			}
		}
	}

	if (new_m1 < col) {
		for (int i = 0; i < col; i++) {
			if (m_v[i][0] == 0 && m_v[i][1] == 0 && m_v[i][2] != 0 && new_m1 < col) {
				for (int j = 0; j < row; j++) {
					result.m_v[new_m1][j] = m_v[i][j];
				}
				new_m1++;
			}
		}
	}
	
	while ((result.front(1) == result.front(2)) || (result.front(0) == result.front(1))) {
		if ((result.front(1) == result.front(2)) && (result.m_v[1][result.front(1)] != 0)) {
			div = result.m_v[1][result.front(1)] / result.m_v[2][result.front(2)];
			for (int i = 0; i < col; i++) {
				result.m_v[2][i] = result.m_v[1][i] - (result.m_v[2][i] * div);
			}
		}

		if ((result.front(0) == result.front(1)) && (result.m_v[1][result.front(1)] != 0)) {
			div = result.m_v[0][result.front(0)] / result.m_v[1][result.front(1)];
			for (int i = 0; i < col; i++) {
				result.m_v[1][i] = result.m_v[0][i] - (result.m_v[1][i] * div);
			}
		}
	}

	
	if ((result.m_v[0][result.front(1)] != 0) && (result.m_v[1][result.front(1)] != 0)) {
		div = result.m_v[0][result.front(1)] / result.m_v[1][result.front(1)];
		for (int j = 0; j < row; j++) {
			result.m_v[0][j] = result.m_v[0][j] - (result.m_v[1][j] * div);
		}
	}
	if ((result.m_v[1][result.front(2)] != 0) && (result.m_v[2][result.front(2)] != 0)) {
		div = result.m_v[1][result.front(2)] / result.m_v[2][result.front(2)];
		for (int j = 0; j < row; j++) {
			result.m_v[0][j] = result.m_v[0][j] - (result.m_v[1][j] * div);
		}
	}



	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			result.m_v[i][j] = result.m_v[i][j] / result.m_v[i][result.front(i)];
		}
	}
	
	return result;
}

int matrix::front(int col) {
	int front = 0;

	for (int i = 0; i < row; i++) {
		if (m_v[col][i] != fraction(0)) {
			front = i;
			break;
		}
	}
	return front;
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

std::ostream& operator<<(std::ostream& os, const PMM& pmm)
{
	os << "Lower matrix below" << std::endl;
	os << pmm.first;
	os << "Upper matrix below" << std::endl;
	os << pmm.second;

	return os;
}

std::istream& operator>>(std::istream& is, matrix& m)
{
	std::cout << "size " << m.row << 'x' << m.col << std::endl;
	for (int i = 0; i < m.m_v.size(); ++i)
	{
		for (int j = 0; j < m.m_v[i].size(); ++j)
		{
			is >> m.m_v[i][j];
		}
	}
	return is;
}
