#include <iostream>
#include <sstream>
#include <string>



#include "fraction.h"
#include "matrix.h"
using namespace std;


std::vector<std::vector<int>> function_input(std::string input)
{
	std::vector<std::vector<int>> a(6, std::vector<int>(6, 0));
	std::vector<std::string> split_vector;
	std::string temp;
	int idx = 0;
	for (int i = 1; i < input.size(); ++i)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			split_vector.push_back(input.substr(idx, i-idx));
			idx = i;
		}
	}
	if (split_vector.size() != 0) split_vector.push_back(input.substr(idx, split_vector.size()-idx));
	if (split_vector.size() == 0) split_vector.push_back(input);
	for (std::string s : split_vector)
	{
		int c = std::stoi(s);
		int x = 0;
		int y = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'x')
			{
				if (i == s.size() - 1)
				{
					x = 1;
				}
				else
				{
					if (s[i + 1] == '^')
					{
						x = std::stoi(s.substr(i + 2, s.size() - 1));
					}
					else if (s[i + 1] == 'y') x = 1;
				}
			}
			if (s[i] == 'y')
			{
				if (i == s.size() - 1)
				{
					y = 1;
				}
				else
				{
					if (s[i + 1] == '^')
					{
						y = std::stoi(s.substr(i + 2, s.size() - 1));
					}
					else if (s[i + 1] == 'x') y = 1;
				}
			}
		}
		a[x][y] = c;
	}
	return a;
}
std::string function_string(std::vector<std::vector<int>> func)
{
	std::string result;
	int dummy = 0;
	for (int i = func.size() - 1; i >= 0; --i)
	{
		for (int j = func[i].size()-1; j >= 0; --j)
		{
			if (func[i][j] != 0)
			{
				if (dummy != 0)
				{
					if (func[i][j] > 0) result.push_back('+');
				}
				result = result + std::to_string(func[i][j]);
				if (i != 0)
				{
					result.push_back('x');
					if (i != 1)
					{
						result.push_back('^');
						result = result + std::to_string(i);
					}
					dummy++;

				}
				if (j != 0)
				{
					result.push_back('y');
					if (j != 1)
					{
						result.push_back('^');
						result = result + std::to_string(j);
					}
					dummy++;
				}
			}
		}
	}
	return result;
}
std::vector<std::vector<int>> dif(std::vector<std::vector<int>> vv, char c)
{
	if (c == 'x')
	{
		for (int i = 1; i < vv.size(); ++i)
		{
			for (int& j : vv[i])
			{
				j = j * i;
			}
			vv[i - 1] = vv[i];
		}
		vv[5] = std::vector<int>(6, 0);
	}
	if (c == 'y')
	{
		for (int i = 1; i < vv.size(); ++i)
		{
			for (int j = 0; j < vv[i].size(); ++j)
			{
				vv[j][i] = vv[j][i] * i;
				vv[j][i - 1] = vv[j][i];
			}
			
		}
		for (int i = 0; i < vv.size(); ++i)
		{
			vv[i][5] = 0;
		}
	}
	return vv;
}


int main()
{
	std::string input;
	cin >> input;
	std::vector<std::vector<int>> aa = function_input(input);
	cout << function_string(dif(aa, 'x'));
}