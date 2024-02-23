/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int res, n;
  vector<bool> book;
  void dfs(int index) {
    if (index == n + 1) {
      res++;
      return;
    }
    for (int i = 1; i <= n; i++) {
      if (book[i] && (index % i == 0 || i % index == 0)) {
        book[i] = false;
        dfs(index + 1);
        book[i] = true;
      }
    }
  }
  int countArrangement(int N) {
    if (N < 3) return N;
    n = N;
    book.resize(n + 1, true);
    res = 0;
    dfs(1);
    return res;
  }
};
// @lc code=end
