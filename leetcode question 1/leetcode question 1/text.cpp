#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
class Solution {
public:
    struct compare {
        bool operator()(const std::pair<std::string, int>& kv1,
            const std::pair<std::string, int>& kv2) {
            return kv1.second > kv2.second ||
                (kv1.second == kv2.second && kv1.first < kv2.first);
        }
    };

    std::vector<std::string> topKFrequent(std:: vector<std::string>& words, int k) {
        std::map<std::string, int> ans;
        for (auto& ch : words) {
            ans[ch]++;
        }
        std::vector<std::pair<std::string, int>> v(ans.begin(), ans.end());
       std::sort(v.begin(), v.end(), compare());
        std::vector<std::string> thev;
        auto it = v.begin();
        while (k--)
        {
            thev.push_back(it->first);
            it++;
        }
        return thev;
    }
};
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> v;
        for (auto& ch : nums)
        {
            auto ret = v.insert(ch);
            if (ret.second == false)
            {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::map<char, int> s1;
       std:: map<char, int> t1;
        for (const auto& ch1 : s) {
            s1[ch1]++;
        }
        for (const auto& ch2 : t) {
            t1[ch2]++;
        }
        auto kv1 = s1.begin();
        auto kv2 = t1.begin();
        while (kv1 != s1.end() || kv2 != t1.end()) {
            if (kv1->first != kv2->first || kv1->second != kv2->second) {
                return false;
            }
            kv1++;
            kv2++;
        }
        return true;
    }
};
