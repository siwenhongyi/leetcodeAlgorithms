/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s == "") return true;
    int index = 0;
    int n = s.size();
    for (auto& iter : t) {
      if (s[index] == iter) {
        if (++index == n) return true;
      }
    }
    return false;
  }
};
// @lc code=end
