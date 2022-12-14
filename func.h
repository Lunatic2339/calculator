#pragma once

#include <vector>
#include <stdarg.h>
#include <iostream>
#include <string>

class func
{
private:
	std::vector<std::vector<int>> f_v;

public:
	func()
	{
		f_v.resize(6);
		for (std::vector<int>& iv : f_v)
		{
			iv.resize(6);
		}

	}

	void dif()
	{
		std::vector<int> replace;
		for (int i = f_v.size() - 1; i > 0; --i)
		{
			int idx = 0;
			replace.push_back(i * f_v[idx++]);
		}
		f_v = replace;
		return;
	}

	friend std::istream& operator>>(const std::istream& is, func& f)
	{
		std::string input;
		is >> input;

		l.m_v.size();
		l.m_v[0].size();

	}


};
func f(6, 1, 2, 3, 7, 1, 9);
f.dif();