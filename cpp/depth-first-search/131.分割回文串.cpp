/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<int> path;
  vector<vector<int>> ans, dp;
  int n;

 private:
  void dfs(int index) {
    if (index >= n) {
      ans.push_back(path);
      return;
    }
    for (int i = index; i < n; i++) {
      if (dp[index][i]) {
        path.push_back(i);
        dfs(i + 1);
        path.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    n = s.size();
    dp.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (j == i + 1)
          dp[i][j] = s[i] == s[j];
        else
          dp[i][j] = int(s[i] == s[j] && dp[i + 1][j - 1]);
      }
    }
    dfs(0);
    vector<vector<string>> res;
    vector<string> temp;
    string t;
    unordered_map<int, string> pos;
    for (auto& it : ans) {
      int m = 0;
      temp.clear();
      for (auto& iter : it) {
        auto& t = pos[n * m + iter - m + 1];
        if (t.empty()) {
          t = s.substr(m, iter - m + 1);
        }
        temp.push_back(t);
        m = iter + 1;
      }
      res.push_back(temp);
    }
    return res;
  }
};

// @lc code=end
