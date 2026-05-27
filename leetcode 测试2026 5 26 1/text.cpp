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
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
            {
                i += 3;
            }
            else
            {
                return nums[i];
            }
        }
        return nums[i];
    }
};
class Solution4 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        sort(numbers.begin(), numbers.end());
        int i = numbers.size() / 2;
        return numbers[i];
    }
};