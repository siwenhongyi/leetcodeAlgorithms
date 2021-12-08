/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  static const int fx[];
  static const int fy[];

 public:
  vector<vector<int>> colorBorder(vector<vector<int>>& mat, int row, int col,
                                  int color) {
    int n = mat.size(), m = mat[0].size(), tag = mat[row][col];
    if (tag == color) return mat;
    vector<vector<bool>> visi(n, vector<bool>(m, false));
    visi[row][col] = true;
    queue<int> q;
    q.push(row);
    q.push(col);
    int x, y, new_x, new_y;
    bool flag;
    while (q.size()) {
      x = q.front();
      q.pop();
      y = q.front();
      q.pop();
      flag = false;
      for (size_t i = 0; i < 4; i++) {
        new_x = x + fx[i], new_y = y + fy[i];
        // cout << new_x << ' ' << new_y << endl;
        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
          flag = true;
          continue;
        }
        if (visi[new_x][new_y]) continue;
        if (mat[new_x][new_y] != tag) {
          flag = true;
          continue;
        }
        visi[new_x][new_y] = true;
        q.push(new_x);
        q.push(new_y);
      }
      if (flag) mat[x][y] = color;
    }
    return mat;
  }
};
const int Solution::fx[] = {1, 0, -1, 0};
const int Solution::fy[] = {0, 1, 0, -1};

// @lc code=end
