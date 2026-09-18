#define  _CRT_SECURE_NO_WARNINGS
//leetcode by 283
#include<vector>
#include<algorithm>
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

//leetcode by 1089
class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int cur = 0;
        int dest = -1;
        while (cur < arr.size()) {
            if (arr[cur]) {
                dest++;
            }
            else {
                dest += 2;
            }
            if (dest >= arr.size() - 1)
                break;
            cur++;
        }
        if (dest == arr.size()) {
            arr[dest - 1] = 0;
            dest -= 2;
            cur--;
        }
        while (cur >= 0) {
            if (arr[cur]) {
                arr[dest] = arr[cur];
            }
            else {
                arr[dest] = 0;
                dest--;
                arr[dest] = 0;
            }
            cur--;
            dest--;
        }
    }
};

//leetcode by 202
class Solution {
public:
    int fanc(int a) {
        int sum = 0;
        while (a) {
            int s = a % 10;
            sum += s * s;
            a /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {

        int slow = n;
        int fast = fanc(n);
        while (slow != fast) {
            slow = fanc(slow);
            fast = fanc(fast);
            fast = fanc(fast);
        }
        if (slow == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};
//leetcode by 611
class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        int n = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 1; i--)
        {
            int left = 0;
            int right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    n += (right - left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return n;
    }
};