#include <iostream>
#include <sstream>
#include <string>



#include "fraction.h"
#include "matrix.h"
using namespace std;



int main()
{

	matrix m(3, 3);
	cin >> m;
	cout << m;
	cout << m.det() << endl;
	cout << m.adj();
}