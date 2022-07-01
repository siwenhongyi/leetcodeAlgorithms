/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
 public:
  int trap(vector<int>& height) {
    stack<int> st;
    int n = height.size();
    int water_lv = 0, res = 0;
    for (int i = 0; i < n; i++) {
      auto&& curr = height[i];
      while (st.size() && height[st.top()] < curr) {
        auto qa = st.top();
        st.pop();
        if (st.empty()) break;
        auto&& left = st.top();
        res += (min(height[left], curr) - height[qa]) * (i - left - 1);
      }
      st.push(i);
    }
    return res;
  }
};
// @lc code=end
//  any test case
int main() {
  Solution s;
  vector<vector<int>> v = {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
                           {4, 2, 0, 3, 2, 5}};
  for (auto&& i : v) {
    cout << s.trap(i) << endl;
  }
  return 0;
}