/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include "head.h"
using namespace std;
// @lc code=start

class UnionSet {
 private:
  vector<int> f;

 public:
  UnionSet(int n) : f(vector(n, -1)) {}

 public:
  int find(int x) { return f[x] < 0 ? x : f[x] = find(f[x]); }
  void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (f[x] > f[y]) swap(x, y);
    f[x] += f[y];
    f[y] = x;
  }
  bool is_union(int x, int y) { return find(x) == find(y); }
};

class Solution {
 private:
  void check(const vector<vector<char>>& board) {
    for (auto& it : board) {
      for (auto& jt : it) {
        cout << jt << ' ';
      }
      cout << endl;
    }
  }

 public:
  void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    int over = n * m + 1;
    UnionSet us(over + 1);
    // check(board);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'X') continue;
        auto&& x = i * m + j;
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
          us.union_set(x, over);
          continue;
        }
        if (board[i - 1][j] == 'O') us.union_set(x, x - m);
        if (board[i][j - 1] == 'O') us.union_set(x, x - 1);
        if (board[i][j + 1] == 'O') us.union_set(x, x + 1);
        if (board[i + 1][j] == 'O') us.union_set(x, x + m);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!us.is_union(i * m + j, over)) board[i][j] = 'X';
      }
    }
  }
};
// @lc code=end
