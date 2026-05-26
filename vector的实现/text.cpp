#define  _CRT_SECURE_NO_WARNINGS
#include"myvector.h"
namespace myvector
{
	static void text1()
	{
		vector<int> s1;
		s1.push_back(4);
		s1.push_back(1);
		s1.push_back(2);
		s1.push_back(3);
		s1.push_back(4);
		s1.push_back(4);
		s1.push_back(4);
		s1.push_back(5);
		s1.push_back(4);
		s1.resize(5);
		s1.resize(10);
		vector<int> s2 = s1;
		s1.push_back(5);
		s2.push_back(6);
		vector<int> s3(10,1);
	
		
	
		print_Container(s1); 
		print_Container(s2);
		print_Container(s3);
		
	}
}
int main()
{
	myvector::text1();
	return 0;
}
