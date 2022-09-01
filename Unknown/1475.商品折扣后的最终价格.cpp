/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector res(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      auto&& now = prices[i];
      while (st.size() && st.top() > now) st.pop();
      if (st.size())
        res[i] = now - st.top();
      else
        res[i] = now;
      st.push(now);
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
