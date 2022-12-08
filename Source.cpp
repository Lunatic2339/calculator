#include <iostream>

#include "fraction.h"

using namespace std;

int main()
{
	fraction fr1(3, 2);
	cout << fr1;
	fr1 = fr1 + 1;
	cout << fr1;
}