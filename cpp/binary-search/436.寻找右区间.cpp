/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& index) {
    if (index.size() <= 1) return vector<int>(index.size(), -1);
    unordered_map<int, int> book;
    int n = index.size(), m = -1, t, q, ans;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      t = index[i][0];
      m = max(m, t);
      if (!book[t]) book[t] = i + 1;
    }
    for (int i = 0; i < n; i++) {
      t = index[i][1];
      q = t;
      ans = -1;
      while (q <= m) {
        if (book[q]) {
          ans = book[q] - 1;
          break;
        }
        q++;
      }
      res.push_back(ans);
    }
    return res;
  }
};
// @lc code=end
