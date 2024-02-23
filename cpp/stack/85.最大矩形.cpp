/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size(), m = matrix[0].size(), res = 0, index = 0;
    vector<vector<int>> ones(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') ones[i][j] = j ? ones[i][j - 1] + 1 : 1;
      }
    }
    for (int j = 0; j < m; j++) {
      vector left(n, -1), right(n, n);
      stack<int> st;
      for (int i = 0; i < n; i++) {
        while (st.size() && ones[st.top()][j] >= ones[i][j]) {
          right[st.top()] = i;
          st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      for (int i = n - 1; i >= 0; i--) {
        res = max(res, (right[i] - left[i] - 1) * ones[i][j]);
      }
    }
    return res;
  }
};
// @lc code=end
