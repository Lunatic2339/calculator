#include <iostream>
#include <sstream>
#include <string>



#include "fraction.h"
#include "matrix.h"
using namespace std;

std::vector<fraction> string_to_fraction(std::vector<std::string> s_v)
{
    std::stringstream ss;
    std::string s_temp;
    std::vector<std::string> s_temp_v;
    fraction f_temp;
    std::vector<fraction> result;
    for (int i = 0; i < s_v.size(); ++i)
    {
        f_temp.setNum(std::stoi(s_v[i]));
        while (std::getline(ss, s_temp, '/'))
        {
            s_temp_v.push_back(s_temp);
            std::cout << s_temp << std::endl;
        }
        if (s_temp_v.size() == 2) f_temp.setDenom(std::stoi(s_temp_v[1]));
        result.push_back(f_temp);
        f_temp.set(0, 1);
    }
    return result;
}

int main()
{
	vector<string> s(9);
    for (string& ss : s)
    {
        cin >> ss;
    }

    vector<fraction> ff = string_to_fraction(s);

    for (fraction f : ff)
    {
        cout << f << endl;
    }

	



}