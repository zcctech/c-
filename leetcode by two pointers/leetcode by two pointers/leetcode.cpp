#define  _CRT_SECURE_NO_WARNINGS
//leetcode by 283
#include<vector>
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int cur = -1;
        int move = 0;
        while (move < nums.size())
        {
            if (nums[move] != 0)
            {
                cur++;
                std::swap(nums[cur], nums[move]);
            }
            move++;
        }

    }
};