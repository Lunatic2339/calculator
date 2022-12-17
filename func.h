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
           return is;
	}

};



