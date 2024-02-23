/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> res;
  string path;
  int all;
  void dfs(int l, int done) {
    if (done == all) {
      res.push_back(path);
      return;
    }
    if (l) {
      path.push_back(')');
      dfs(l - 1, done + 1);
      path.pop_back();
    }
    if (l + done != all) {
      path.push_back('(');
      dfs(l + 1, done);
      path.pop_back();
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    if (!n) return {};
    if (n == 1) return {"()"};
    all = n;
    dfs(0, 0);
    return res;
  }
};
// @lc code=end
