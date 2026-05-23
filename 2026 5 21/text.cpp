#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        if (m == 0 || n == 0)
        {
            string s = "0";
            return s;
        }
        vector<int> s1(m + n);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                s1[i + j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for (int i = m + n - 1; i > 0; i--)
        {
            s1[i - 1] += s1[i] / 10;
            s1[i] %= 10;
        }
        string ans;
        int judge = s1[0] == 0 ? 1 : 0;
        while (judge < m + n)
        {
            ans.push_back(s1[judge]);
            judge++;
       }
        for (auto& ch : ans)
        {
            ch += '0';
        }
        return ans;

    }
};
int main()
{
    Solution x;
    string s1 =x.multiply("9", "99");
    cout << s1;
    return 0;
}