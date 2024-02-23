/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int largestRectangleArea(vector<int>& mat) {
    int n = mat.size(), index = 0;
    vector left(n, -1), right(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (st.size() && mat[i] <= mat[st.top()]) {
        right[st.top()] = i;
        st.pop();
      }
      left[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
      res = max(res, mat[i] * (right[i] - left[i] - 1));
    return res;
  }
};
// @lc code=end
