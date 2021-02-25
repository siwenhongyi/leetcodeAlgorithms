/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

#include "head.h"
using namespace std;
// @lc code=start
using PII = pair<int, int>;

const int fx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int fy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    int n = board.size(), m = board[0].size();
    int x = click.front(), y = click.back();
    char &c = board[x][y];
    if (c != 'E') {
      c = c == 'M' ? 'X' : c;
      return board;
    }
    queue<PII> q;
    vector<PII> t(8);
    vector<vector<bool>> vi(n, vector<bool>(m, true));
    int new_x, new_y, cnt;
    vi[x][y] = false;
    q.push({x, y});
    while (q.size()) {
      auto &qa = q.front();
      x = qa.first, y = qa.second;
      q.pop();
      t.clear();
      cnt = 0;
      for (int i = 0; i < 8; i++) {
        new_x = x + fx[i], new_y = y + fy[i];
        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
        cnt += board[new_x][new_y] == 'M';
        if (vi[new_x][new_y] && board[new_x][new_y] == 'E')
          t.push_back({new_x, new_y});
      }
      if (cnt) {
        board[x][y] = '0' + cnt;
      } else {
        board[x][y] = 'B';
        for (auto &it : t) {
          q.push(it);
          vi[it.first][it.second] = false;
        }
      }
    }
    return board;
  }
};
// @lc code=end
