/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  unordered_map<int, int> has;
  int dfs(int n) {
    if (n <= 1) return n;
    if (has.count(n)) return has[n];
    int x = min({dfs(n / 3) + n % 3, dfs(n / 2) + n % 2, n - 1}) + 1;
    has[n] = x;
    return x;
  }
  int minDays(int n) { return dfs(n); }
};
// @lc code=end
