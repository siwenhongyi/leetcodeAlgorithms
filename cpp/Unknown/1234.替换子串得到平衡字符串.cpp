/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串 Medium (44.43%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int balancedString(string s) {
    vector<int> cnt(256, 0);
    for (auto c : s) {
      cnt[c]++;
    }
    int n = s.size();
    int m = n / 4, res = n;
    auto check = [&]() {
      if (cnt['Q'] > m || cnt['W'] > m || cnt['E'] > m || cnt['R'] > m) {
        return false;
      }
      return true;
    };
    if (check()) return 0;
    for (int l = 0, r = 0; l < n; l++) {
      while (r < n && !check()) cnt[s[r++]]--;
      if (!check()) break;
      res = min(res, r - l);
      cnt[s[l]]++;
    }
    return res;
  }
};
// @lc code=end
