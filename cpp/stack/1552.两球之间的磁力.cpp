/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool check(const int x, const vector<int>& p, const int& m) {
    int cou = 0;
    int target = p[0] + x;
    for (int i = 0; i < p.size(); i++) {
      if (p[i] >= target) {
        cou++;
        target = p[i] + x;
      }
    }
    return cou >= m - 1;
  }
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int left = INT_MAX, right = (position.back() - position.front()) / (m - 1);
    for (int i = 1; i < position.size() - 1; i++) {
      if (position[i] - position[i + 1] < left)
        left = position[i] - position[i + 1];
    }
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (check(mid, position, m))
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left - 1;
  }
};

// @lc code=end
