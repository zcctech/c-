#define  _CRT_SECURE_NO_WARNINGS
#include"bstree.h"
int main()
{
	bstree<int> tree;
	int a[10] = { 3,9,5,11,13,2,6,14,10,7 };
	for (const auto e : a)
	{
		tree.insert(e);
	}
	tree.inorder();
	for (const auto e : a)
	{
		tree.erase(e);
		tree.inorder();
	}
	std::cout<<tree.find(3);
	bstree<int> tree2 =tree;
	return 0; 
}