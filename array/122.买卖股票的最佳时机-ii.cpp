/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& p) {
    int n = p.size(), res = 0;

    vector<int> in(n, 0), out(n, 0);
    in[0] = -p[0];
    for (int i = 1; i < n; i++) {
      in[i] = max(out[i - 1] - p[i], in[i - 1]);
      out[i] = max(in[i - 1] + p[i], out[i - 1]);
      res = max(res, out[i]);
    }
    return out[n - 1];
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  Solution s;
  vector<vector<int>> v = {
      {7, 1, 5, 3, 6, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}};
  for (auto&& i : v) {
    cout << s.maxProfit(i) << endl;
  }
  return 0;
}
