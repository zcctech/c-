#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	string si="hello world";
	std::string::iterator it;
	for ( it = si.begin(); it < si.end(); it++)
	{
		cout << *it<<' ';
	}
	cout << endl;
	std::string::reverse_iterator rit;
	for (rit = si.rbegin(); rit < si.rend(); rit++)
	{
		cout << *rit << ' ';
	}
	return 0;
}
