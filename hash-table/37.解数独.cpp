/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  using PII = pair<int, int>;
  vector<bitset<9>> row, col, room;
  bitset<9> temp;
  void get_nums(int r, int c) {
    temp = bitset<9>(~(row[r] | col[c] | room[(r / 3) * 3 + c / 3]));
  }
  PII get_index(vector<vector<char>>& board) {
    int max_empty = 10;
    PII res;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') continue;
        get_nums(i, j);
        if (temp.count() < max_empty) {
          res = {i, j};
          max_empty = temp.count();
        }
      }
    }
    return res;
  }
  void set_count(u_short r, u_short c, u_short n, bool is_fill) {
    // row[r][n] = is_fill ? 1 : 0;
    // col[c][n] = is_fill ? 1 : 0;
    // room[(r / 3) * 3 + c / 3][n] = is_fill ? 1 : 0;

    temp = bitset<9>(1 << n);
    row[r] = is_fill ? (row[r] | temp) : (row[r] ^ temp);
    col[c] = is_fill ? (col[c] | temp) : (col[c] ^ temp);
    room[(r / 3) * 3 + c / 3] = is_fill ? (room[(r / 3) * 3 + c / 3] | temp)
                                        : (room[(r / 3) * 3 + c / 3] ^ temp);
  }
  void p(vector<vector<char>>& board) {
    for (auto it : board) {
      for (auto iter : it) {
        if (iter == '.')
          cout << 'X';
        else
          cout << int(iter - '1');
      }
      cout << endl;
    }
  }
  bool dfs(vector<vector<char>>& board, int nums) {
    cout << nums << ' ';
    if (nums == 0) return true;
    auto&& [x, y] = get_index(board);
    get_nums(x, y);
    for (size_t n = 0; n < temp.size(); n++) {
      if (!temp.test(n)) continue;
      set_count(x, y, n, true);
      board[x][y] = '1' + n;
      auto&& res = dfs(board, nums - 1);
      if (res) return true;
      board[x][y] = '.';
      set_count(x, y, n, false);
    }
    return false;
  }

 public:
  Solution()
      : row(vector<bitset<9>>(9, bitset<9>())),
        col(vector<bitset<9>>(9, bitset<9>())),
        room(vector<bitset<9>>(9, bitset<9>())) {}
  void solveSudoku(vector<vector<char>>& board) {
    int nums = 81;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        nums -= 1;
        temp = bitset<9>(1 << (board[i][j] - '1'));
        row[i] |= temp, col[j] |= temp, room[(i / 3) * 3 + j / 3] |= temp;
      }
    }
    auto&& res = dfs(board, nums);
    cout << (res ? 1 : 0) << endl;
    return;
  }
};
// @lc code=end
