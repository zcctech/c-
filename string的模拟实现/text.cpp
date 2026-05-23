#define  _CRT_SECURE_NO_WARNINGS
#include"mystring.h"
namespace mystring
{

	static void text1()
	{
		string s1;
		string s2 = "abcdefg";
		s2.insert(0, "xxxxxxxx");
		cout << s2;

		
	}
}
int main()
{
	mystring::text1();
	return 0;
}