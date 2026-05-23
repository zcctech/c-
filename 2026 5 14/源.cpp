#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
class Solution {
public:
    string reverseStr(string s, int k) {
        int coust = -1;
        int end = -1;
        int begin = 0;
        while ((s.size() - 1) >= coust)
        {
            coust += 2 * k;
            end += k;
            int begin1 = begin;
            int end1 = end;
            while (begin1 <= end1)
            {
                swap(s[begin1], s[end1]);
            }
            begin = end + 1;

        }
        return s;
    }
};
using namespace std;
int main()
{
	string s = "abcdefg";
    s=Solution::reverseStr(s, 2);
	return 0;
}