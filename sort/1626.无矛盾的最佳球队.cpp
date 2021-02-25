/*
* @lc app=leetcode.cn id=1626 lang=cpp
*
* [1626] 无矛盾的最佳球队
*/

#include"head.h"
using namespace std;
// @lc code=start
using PII = pair<int, int>;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        if (ages.size()==1) return scores[0];
        vector<PII> s;
        int n = ages.size();
        for (int i = 0; i <n; i++)
            s.push_back({ ages[i],scores[i] });
        sort(s.begin(), s.end(), [](PII& s, PII& t) {if (s.first != t.first)return s.first < t.first; return s.second < t.second; });
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
            dp[i] = s[i].second;
        int res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (s[i].second >= s[j].second)
                    dp[i] = max(dp[j] + s[i].second, dp[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// @lc code=end

