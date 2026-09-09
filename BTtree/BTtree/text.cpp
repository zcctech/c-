#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include "BTtree.h"
#include"set.h"
#include"map.h"
using namespace std;
int main()
{
    mymap<int, std::string> m;

    m[3] = "three";
    m[1] = "one";
    m[5] = "five";

    std::cout << m[3] << std::endl;

    m[3] = "THREE";

    std::cout << m[3] << std::endl;

    std::cout << "[" << m[100] << "]" << std::endl;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first
            << ":"
            << it->second
            << std::endl;
    }
	return 0;
}
