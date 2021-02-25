/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int compareVersion(string s, string t) {
    int x, y;
    int i, j, k, n = s.size(), m = t.size();
    i = j = 0;
    while (i < n || j < m) {
      if (i < n) {
        while (i < n && s[i] == '0') i++;
        x = atoi(s.substr(i).c_str());
        while (i < n && s[i] != '.') i++;
        i++;
      } else
        x = 0;
      if (j < m) {
        while (j < m && t[j] == '0') j++;
        y = atoi(t.substr(j).c_str());
        while (j < m && t[j] != '.') j++;
        j++;
      } else
        y = 0;
      if (x > y)
        return 1;
      else if (x < y)
        return -1;
    }
    return 0;
  }
};

// @lc code=end
