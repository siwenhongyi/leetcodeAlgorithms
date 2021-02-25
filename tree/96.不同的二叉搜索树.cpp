/*
* @lc app=leetcode.cn id=96 lang=cpp
*
* [96] 不同的二叉搜索树
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp{1, 1};
    dp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
      int t = 0;
      for (int j = 0; j < i; j++) {
        t += dp[j] * dp[i - j - 1];
      }
      dp[i] = t;
    }
    return dp[n];
  }
};
// @lc code=end

