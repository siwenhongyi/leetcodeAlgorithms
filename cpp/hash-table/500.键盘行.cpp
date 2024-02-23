/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  static const map<char, int> one_line;

 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> res;
    int t, p;
    for (auto& it : words) {
      t = Solution::one_line.at(tolower(it[0]));
      for (auto& c : it) {
        p = Solution::one_line.at(tolower(c));
        if (t != p) break;
      }
      if (t == p) res.push_back(it);
    }
    return res;
  }
};

const map<char, int> Solution::one_line = {
    {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0},
    {'i', 0}, {'o', 0}, {'p', 0}, {'a', 1}, {'s', 1}, {'d', 1}, {'f', 1},
    {'g', 1}, {'h', 1}, {'j', 1}, {'k', 1}, {'l', 1}, {'z', 2}, {'x', 2},
    {'c', 2}, {'v', 2}, {'b', 2}, {'n', 2}, {'m', 2}};

// @lc code=end
