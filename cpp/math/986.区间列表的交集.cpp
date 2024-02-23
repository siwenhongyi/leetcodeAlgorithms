/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    int n = A.size(), m = B.size();
    if (!n || !m) return {};
    vector<vector<int>> res;
    int x, y;
    for (int i = 0; i < n; i++) {
      x = A[i][0], y = A[i][1];
      for (int j = 0; j < m; j++) {
        if (B[j][0] > y) break;
        if (B[j][1] < x) continue;
        res.push_back({max(x, B[j][0]), min(y, B[j][1])});
      }
    }
    return res;
  }
};

// @lc code=end
