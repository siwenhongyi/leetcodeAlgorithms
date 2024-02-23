/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> v(board.begin(), board.end());
    for (unsigned int i = 0; i < v.size(); i++) {
      for (unsigned int j = 0; j < v[i].size(); j++) {
        int live = 0;
        int a;
        bool x = j, y = j == v[i].size() - 1;
        if (i != 0) {
          a = (v[i - 1][j] == 1);
          a += x ? (v[i - 1][j - 1] == 1) : 0;
          a += y ? 0 : v[i - 1][j + 1] == 1;
          live += a;
        }
        if (x && v[i][j - 1]) live++;
        if (!y && v[i][j + 1]) live++;
        if (i != v.size() - 1) {
          a = (v[i + 1][j] == 1);
          a += x ? (v[i + 1][j - 1] == 1) : 0;
          a += y ? 0 : v[i + 1][j + 1] == 1;
          live += a;
        }
        if (v[i][j]) {
          if (live < 2)
            board[i][j] = 0;
          else if (live > 3)
            board[i][j] = 0;
        } else if (live == 3)
          board[i][j] = 1;
      }
    }
  }
};
// @lc code=end
