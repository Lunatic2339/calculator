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

	//����
	matrix power(int n);
	//��ġ���
	matrix tr();
	//�����
	matrix sub(int r, int c);
	//�������
	matrix adj();
	//�����
	matrix inverse();
	// LU����
	PMM LUdecompose();


	//��Ľ�
	fraction det();
	//���μ�
	fraction cof(int r, int c);
	//����� ��ٸ���
	matrix echelon();
	//0�� �ƴ� ���� ������ ã��
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

