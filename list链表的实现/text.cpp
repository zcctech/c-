#define  _CRT_SECURE_NO_WARNINGS
#include"mylist.h"
namespace mylist
{
	static void text()
	{
		list<int> it;
		it.insert(it.begin(), 1);
		it.insert(it.begin(), 2);
		it.insert(it.begin(), 3);
		it.insert(it.begin(), 4);
		it.insert(it.begin(), 4);
		it.insert(it.begin(), 4);
		it.insert(it.begin(), 4);
		it.insert(it.begin(), 4);
		it.insert(it.begin(), 3);
		it.insert(it.begin(), 3);
		it.insert(it.begin(), 3);
		it.insert(it.begin(), 3);
		it.erase(--it.end());
		it.erase(--it.end());
		it.erase(--it.end());
		print_container(it);
	}
};
int main()
{
	mylist::text();
	return 0;
}