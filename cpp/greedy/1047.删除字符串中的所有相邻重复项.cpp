/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string removeDuplicates(string S) {
    if (S.size() <= 1) return S;
    string res(1, S.front());
    for (unsigned int i = 1; i < S.size(); i++)
      if (res.empty() || S[i] != res.back())
        res.push_back(S[i]);
      else
        res.pop_back();
    return res;
  }
};

// @lc code=end
