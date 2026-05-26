#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//leetcode 118
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> s1(numRows);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                s1[i].resize(i + 1);
                if (j == 0 || i == j)
                {
                    s1[i][j] = 1;
                }
                else
                {
                    s1[i][j] = s1[i - 1][j] + s1[i - 1][j - 1];
                }

            }
        }
        return s1;
    }
};

