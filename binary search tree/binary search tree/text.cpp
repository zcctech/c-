#define  _CRT_SECURE_NO_WARNINGS
#include"bstree.h"
#include<string>
#ifdef _WIN32
#include <Windows.h>
#endif
int main()
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif
	bstree<std::string,std::string> dict;
	dict.insert("insert", "插入");
	dict.insert("erase", "删除");
	dict.insert("left", "左边");
	dict.insert("string", "字符串");
	std::string str;
	while (std::cin >> str)
	{
		const auto ret = dict.find(str);
		if (ret)
		{
			std::cout << str << ":" << ret->value <<std:: endl;
		}
		else
		{
			std::cout << "单词拼写错误" << std::endl;
		}
	}
	std::string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	bstree<std::string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.find(str);
		if (ret == NULL)
		{
			countTree.insert(str, 1);
		}
		else
		{
			ret->value++;
		}
	}
	countTree.inorder();
	return 0; 
}
