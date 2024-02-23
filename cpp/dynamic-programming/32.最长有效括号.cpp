/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector dp(n,0);
        int res = 0;
        for(int i = 1;i<n; res = max(res,dp[i++])) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = 2;
                     if(i - 2 >=0) dp[i] = dp[i] + dp[i-2];
                } else if(dp[i-1] > 0) {
                    if(i-dp[i-1]-1 >=0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1] + 2;
                        if(i-dp[i-1]-2 >= 0) {
                            dp[i] = dp[i] + dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

