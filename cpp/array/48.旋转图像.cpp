/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <bits/stdc++.h>
using namespace std;
int one = 0;

// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int temp;
    if (n <= 1) return;
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        auto &a = matrix[i][j], &b = matrix[j][n - i - 1],
             &c = matrix[n - i - 1][n - j - 1], &d = matrix[n - j - 1][i];
        temp = a;
        a = d;
        d = c;
        c = b;
        b = temp;
      }
    }
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  Solution s;
  vector<vector<vector<int>>> cases = {
      {{1}},
      {{1, 2}, {1, 2}},
      {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}},
      {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
      {{1, 2, 3, 4, 5},
       {1, 2, 3, 4, 5},
       {1, 2, 3, 4, 5},
       {1, 2, 3, 4, 5},
       {1, 2, 3, 4, 5}},
      {{1, 2, 3, 4, 5, 6},
       {1, 2, 3, 4, 5, 6},
       {1, 2, 3, 4, 5, 6},
       {1, 2, 3, 4, 5, 6},
       {1, 2, 3, 4, 5, 6},
       {1, 2, 3, 4, 5, 6}},
      {{1, 2, 3, 4, 5, 6, 7},
       {1, 2, 3, 4, 5, 6, 7},
       {1, 2, 3, 4, 5, 6, 7},
       {1, 2, 3, 4, 5, 6, 7},
       {1, 2, 3, 4, 5, 6, 7},
       {1, 2, 3, 4, 5, 6, 7},
       {1, 2, 3, 4, 5, 6, 7}},
      {{1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8},
       {1, 2, 3, 4, 5, 6, 7, 8}},
      {
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},
          {1, 2, 3, 4, 5, 6, 7, 8, 9},

      }};
  if (one) {
    auto i = cases[one - 1];
    cases = {i};
  }
  for (auto &case_ : cases) {
    s.rotate(case_);
    for (auto &row : case_) {
      for (auto &col : row) {
        cout << col << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
