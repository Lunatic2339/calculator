#include <iostream>
#include <sstream>
#include <string>



#include "fraction.h"
#include "matrix.h"
using namespace std;



int main()
{

	fraction b[9];
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	b[3] = 4;
	b[4] = 5;
	b[5] = 6;
	b[6] = 7;
	b[7] = 8;
	b[8] = 9;
	
	matrix c = matrix(3, 3, b[9]);
	cout << c;
}