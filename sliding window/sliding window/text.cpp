#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
//leetcode by 209
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int right = 0;
        int key = 0;
        int min = INT_MAX;
        int size = nums.size();
        for (right = 0; right < size; right++) {
            key += nums[right];
            while (key >= target) {
                int newmin = right - left + 1;
                if (newmin < min) {
                    min = newmin;
                }
                key -= nums[left];
                left++;
            }

        }
        return min == INT_MAX ? 0 : min;
    }
};