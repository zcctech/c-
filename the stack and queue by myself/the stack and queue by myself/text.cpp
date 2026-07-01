#define  _CRT_SECURE_NO_WARNINGS
#include"mystack.h"
int main()
{
	bit::stack<int> s1;
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	cout << s1.size() << endl;

	return 0;
}