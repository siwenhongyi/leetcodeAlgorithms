/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string S) {
    if (!S.size()) return {0, 0};
    int res = 0;
    int len = 0;
    for (int i = 0; i < S.size(); i++) {
      if (len + widths[S[i] - 'a'] <= 100)
        len += widths[S[i] - 'a'];
      else {
        res++;
        len = widths[S[i] - 'a'];
      }
    }
    return {res + 1, len};
  }
};

// @lc code=end
