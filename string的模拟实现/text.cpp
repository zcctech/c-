#define  _CRT_SECURE_NO_WARNINGS
#include"mystring.h"
namespace mystring
{

	void text1()
	{
		mystring::string s1="abcdefg";
		/*for (const auto ch : s1)
		{
			cout << ch << endl;
		}
		*/
		
		s1.insert(0,"xxxxyyyy");
		cout << s1.c_str()<<endl;
		s1.erase(3, 3);
		cout << s1.c_str()<<endl;
		cout << s1.find("abcd", 0) << endl;
		string s2 = s1.substr(5, 3);
		cout << s2.c_str() << endl;
		cout << (s1 >= s2 )<< endl;
		cin >> s1;
		cout << s1 << endl;
	}
}
int main()
{
	mystring::text1();
	return 0;
}