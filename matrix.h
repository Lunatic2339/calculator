#pragma once

#include "fraction.h"

#include <vector>
#include <iostream>


#define VVF std::vector<std::vector<fraction>>
#define VF std::vector<fraction>
#define PMM std::pair<matrix, matrix>

class matrix
{
private:
	VVF m_v;
	int row;
	int col;
public:
	matrix();
	matrix(int row, int col, int num = 0);
	matrix(int row, int col, fraction num);
	matrix(int rowcol, int n, bool idt);
	matrix(int rowcol, fraction fr, bool idt);

	matrix power(int n);
	matrix tr();
	matrix sub(int r, int c);
	matrix adj();
	matrix inverse();
	std::pair<matrix, matrix> LUdecompose();



	fraction det();
	fraction cof(int r, int c);

	matrix operator+(matrix m);
	matrix operator+(int n);
	matrix operator+(fraction fr);
	matrix operator-(matrix m);
	matrix operator-(int n);
	matrix operator-(fraction fr);
	matrix operator*(matrix m);
	matrix operator*(int k);
	matrix operator*(fraction fr);
	matrix operator/(int k);
	matrix operator/(fraction fr);

	friend std::ostream& operator<<(std::ostream& os, const matrix& m);
	friend std::istream& operator>>(std::istream& is, matrix& m);

};