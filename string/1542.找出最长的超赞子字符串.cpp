/*
* @lc app=leetcode.cn id=1542 lang=cpp
*
* [1542] 找出最长的超赞子字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int longestAwesome(string s) {
        vector<int> first(1<<10, -1);
        vector<int> ans = { 0 };
        for (int i = 0; i < 10; i++)
            ans.emplace_back(1 << i);
        first[0] = 0;
        int n = s.size(), st = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int t = s[i-1] - '0';
            st ^= (1 << t);
            if (first[st] == -1)
                first[st] = i;
            for (auto& it : ans) {
                int need = it ^ st;
                if (first[need] != -1)
                    res = max(res, i - first[need]);
            }
        }
        return res;
    }
};

// @lc code=end

