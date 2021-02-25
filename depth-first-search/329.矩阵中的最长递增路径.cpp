/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

#include "head.h"
using namespace std;
// @lc code=start
int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};

class Solution {
 private:
  int m, n;
  vector<vector<int>> book, pos;

 public:
  int DFS(int x, int y) {
    if (book[x][y] != 0) return book[x][y];
    int new_x, new_y;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      new_x = x + fx[i];
      new_y = y + fy[i];
      if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
          pos[new_x][new_y] > pos[x][y])
        book[x][y] = max(book[x][y], DFS(new_x, new_y));
    }
    return ++book[x][y];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int res = 0;
    if (!matrix.size() || !matrix[0].size()) return res;
    m = matrix.size();
    n = matrix[0].size();
    vector<vector<int>> v(m, vector<int>(n, 0));
    pos = matrix;
    book.swap(v);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) res = max(res, DFS(i, j));

    return res;
  }
};

// @lc code=end
