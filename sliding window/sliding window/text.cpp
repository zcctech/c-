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
//leetcode by 1004
class Solution {
public:
    int longestOnes(std:: vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int num = 0;
        int size = nums.size();
        while (right < size) {
            if (nums[right] == 0) {
                num++;
            }
            while (num > k) {
                left++;
                if (nums[left - 1] == 0) {
                    num--;
                }
            }
            maxlen = std::max(maxlen, right - left + 1);

            right++;
        }
        return maxlen;
    }
};
//leetcode by 3
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int ret = 0;
        int left = 0;
        int right = 0;
        int size = s.size();
        int hash[128] = { 0 };
        while (right < size)
        {
            hash[s[right]]++;

            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;
            }
            ret = std::max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};
//leetcode by 1658
class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int sum = 0;
        int left = 0;
        int right = 0;
        int size = nums.size();
        int s = 0;
        int len = 0;
        for (auto a : nums) {
            sum += a;
        }
        int target = sum - x;
        if (target < 0) {
            return -1;
        }
        else if (target == 0) {
            return size;
        }

        while (right < size) {
            s += nums[right];
            while (s > target) {
                s -= nums[left++];
            }
            if (s == target) {
                len = std::max(len, right - left + 1);
                s -= nums[left++];
            }

            right++;
        }
        return len != 0 ? size - len : -1;
    }
};


//leetcode by 438
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int hash1[26] = { 0 };
        int hash2[26] = { 0 };
        for (auto ch : p) {
            hash1[ch - 'a']++;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        int size = s.size();
        std::vector<int> ans;
        while (right < size) {
            hash2[s[right] - 'a']++;
            if (hash2[s[right] - 'a'] <= hash1[s[right] - 'a']) {
                count++;
            }

            if (right - left + 1 > p.size()) {

                if (hash2[s[left] - 'a'] <= hash1[s[left] - 'a']) {
                    count--;
                }
                hash2[s[left] - 'a']--;
                left++;
            }
            if (count == p.size()) {
                ans.push_back(left);
            }
            right++;
        }
        return ans;
    }
};