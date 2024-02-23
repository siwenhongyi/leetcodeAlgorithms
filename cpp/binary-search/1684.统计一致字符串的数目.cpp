/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> pos;
    int res = 0, flag = 1;
    for (auto& it : allowed) pos.insert(it);
    for (auto& it : words) {
      flag = 1;
      for (auto& iter : it) {
        flag = pos.count(iter);
        if (!flag) break;
      }
      res += flag;
    }
    return res;
  }
};
// @lc code=end
