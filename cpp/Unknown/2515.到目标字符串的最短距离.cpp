/*
 * @lc app=leetcode.cn id=2515 lang=cpp
 *
 * [2515] 到目标字符串的最短距离
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    if (target == words[startIndex]) return 0;
    int res = (1 << 30), n = words.size();
    for (int i = 0; i < n && res != 1; i++) {
      if (words[i] == target) {
        if (i < startIndex) {
          res = min(res, startIndex - i);
          res = min(res, n - startIndex + i);
        } else {
          res = min(res, i - startIndex);
          res = min(res, startIndex + n - i);
        }
      }
    }
    return res == 1 << 30 ? -1 : res;
  }
};
// @lc code=end
