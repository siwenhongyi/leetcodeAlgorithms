/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
#include "head.h"
// @lc code=start
class Solution {
 private:
  int n, res, t;
  void dfs(const string& s, int& index) {
    // cout << s[index] << ' ' << endl;
    if (index >= n) return;
    t = index;
    while (index < n && s[index++] != ',')
      ;
    if (s[t] == '#') {
      return;
    }
    dfs(s, index);  // left
    if (index >= n) {
      res = false;
      return;
    }
    dfs(s, index);  // right
  }

 public:
  bool isValidSerialization(string preorder) {
    if (preorder.empty()) return false;
    n = preorder.size();
    res = true;
    int index = 0;
    dfs(preorder, index);
    return index >= n && res;
  }
};
// @lc code=end
