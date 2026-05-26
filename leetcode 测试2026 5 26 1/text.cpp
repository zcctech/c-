#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//leetcode 118
class Solution1 {
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
class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tep;
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                i += 2;
            }
            else
            {
                tep.push_back(nums[i]);
                i++;
            }
        }
        if (tep.size() == 1)
        {
            tep.push_back(nums[i]);
        }
        return tep;
    }
};
