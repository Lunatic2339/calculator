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
	matrix(int row, int col, fraction num[]);
	matrix(int rowcol, int n, bool idt);
	matrix(int rowcol, fraction fr, bool idt);
	matrix(VF vf, int row, int col);

	void set_rowcol(int row, int col, int num = 0);
	void set_by_vector(VF vf, int row, int col);
	VF matrix_to_vector();

	//제곱
	matrix power(int n);
	//전치행렬
	matrix tr();
	//소행렬
	matrix sub(int r, int c);
	//수반행렬
	matrix adj();
	//역행렬
	matrix inverse();
	// LU분해
	PMM LUdecompose();


	//행렬식
	fraction det();
	//여인수
	fraction cof(int r, int c);
	//기약행 사다리꼴
	matrix echelon();
	//0이 아닌 열의 시작을 찾음
	int front(int col);

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
	friend std::ostream& operator<<(std::ostream& os, const PMM& pmm);

	friend std::istream& operator>>(std::istream& is, matrix& m);

};

