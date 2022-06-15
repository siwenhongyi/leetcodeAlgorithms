/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> res;
  string path;
  int n;
  static const map<int, string> pos;
  void dfs(const string& s, int index) {
    if (index == n) {
      res.push_back(path);
      return;
    }
    for (auto& ch : pos.at(s[index] - '0')) {
      path.push_back(ch);
      dfs(s, index + 1);
      path.pop_back();
    }
  }

 public:
  vector<string> letterCombinations(string s) {
    n = s.size();
    if (!n) return res;
    dfs(s, 0);
    return res;
  }
};
const map<int, string> Solution::pos = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                        {5, "jkl"}, {6, "mno"}, {7, "qprs"},
                                        {8, "tuv"}, {9, "wxyz"}};

// @lc code=end
