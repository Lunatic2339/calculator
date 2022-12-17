#pragma once

#include <vector>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <sstream>
#include "fraction.h"


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

	void dif(char c)
	{
		std::vector<std::vector<int>> replace(6, std::vector<int>(6));
		if (c == 'x')
		{
			for (int i = 1; i < f_v.size(); ++i)
			{
				for (int& j : f_v[i])
				{
					j = j * i;
					f_v[i - 1] = f_v[i];
				}
			}
			f_v[5] = std::vector<int>(6, 0);
		}
		if (c == 'y')
		{
			for (int i = 1; i < f_v.size(); ++i)
			{
				for (int j = 1; j < f_v[i].size(); ++j)
				{
					f_v[i][j - 1] = f_v[i][j] * j;
				}
			}
			for (int i = 0; i < f_v.size(); ++i)
			{
				f_v[i][5] = 0;
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const func& fx)
	{
		for (int i = fx.f_v.size() - 1; i >= 0; --i)
		{
			for (int j = fx.f_v[i].size() - 1; j >= 0; --j)
			{
				if (fx.f_v[i][j] != 0)
				{
					os << fx.f_v[i][j];
					if (i != 0)
					{
						os << 'x';
						if (i != 1) os << '^' << i;
						if (j != 0) os << '*';
					}
					if (j != 0)
					{
						os << 'y';
						if (j != 1) os << '^' << j;
					}
				}
			}
		}
	}
	friend std::istream& operator>>(std::istream& is, func& fx)
	{
		std::string function;
		is >> function;
		std::vector<std::string> result;
		std::stringstream ss(function);
		std::string temp1;
		std::string temp2;
		while (std::getline(ss, temp1, '+')) 
		{
			std::stringstream sss(temp1);
			while (std::getline(sss, temp2, '-')) {
				result.push_back(temp2);
			}
		}

	}

};

std::vector<fraction> string_to_fraction(std::vector<std::string> s_v)
{
    std::vector<fraction> result;
    fraction f_temp(0,1);
    std::stringstream ss;
    std::stringstream ssInt;
    std::stringstream ssInt2;
    std::string temp;
    int n_temp;
    int d_temp;
    std::vector<std::string> v_temp;
    for (int i = 0; i < s_v.size(); ++i)
    {
       ss.str(s_v[i]);
       while (std::getline(ss, temp, '/'))
       {
          v_temp.push_back(temp);
       }
       ssInt.str(v_temp[0]);
       ssInt >> n_temp;
       f_temp.set(n_temp, 1);
       if(v_temp.size() == 2)
       {
          ssInt2.str(v_temp[1]);
          ssInt2 >> d_temp;
          f_temp.set(n_temp, d_temp);
       }
       result.push_back(f_temp);
       v_temp.clear();
       f_temp.set(0, 1);
    }
    return result;
}
