#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	fraction fr1(1, 2, 2);
	fraction fr2(2, -3, 3);
	fraction fr3 = fr1 + fr2;
	fraction fr4 = fr2 + fr1;
	fraction fr5 = fr1 + 3;
	fraction fr6 = fr1 - fr2;
	fr1.Print();
	fr2.Print();
	fr3.Print();
	fr4.Print();
	fr5.Print();
	fr6.Print();
}