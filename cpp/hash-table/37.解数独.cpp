/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include "head.h"
using namespace std;
// @lc code=start
struct Node {
  int x, y;
  Node(int x, int y) : x(x), y(y) {}
};
class NodeCmp {
 public:
  bool operator()(const Node& lhs, const Node& rhs) const {
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
  }
};

map<Node, int, NodeCmp> mp;

class Solution {
 private:
  using PII = pair<int, int>;
  using BT9 = bitset<9>;
  vector<BT9> row, col, room;
  BT9 get_nums(int r, int c) {
    return BT9(~(row[r] | col[c] | room[(r / 3) * 3 + c / 3]));
  }
  PII get_index(vector<vector<char>>& board) {
    int max_empty = 10;
    PII res;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') continue;
        auto&& temp = get_nums(i, j);
        if (temp.count() < max_empty) {
          res = {i, j};
          max_empty = temp.count();
        }
      }
    }
    return res;
  }
  void set_count(short r, short c, short n, bool is_fill) {
    BT9 temp(1 << n);
    row[r] = is_fill ? (row[r] | temp) : (row[r] ^ temp);
    col[c] = is_fill ? (col[c] | temp) : (col[c] ^ temp);
    room[(r / 3) * 3 + c / 3] = is_fill ? (room[(r / 3) * 3 + c / 3] | temp)
                                        : (room[(r / 3) * 3 + c / 3] ^ temp);
  }
  bool dfs(vector<vector<char>>& board, int nums) {
    if (nums == 0) return true;
    auto&& [x, y] = get_index(board);
    auto&& temp = get_nums(x, y);
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
      : row(vector<BT9>(9, BT9())),
        col(vector<BT9>(9, BT9())),
        room(vector<BT9>(9, BT9())) {}
  void solveSudoku(vector<vector<char>>& board) {
    return;
    int nums = 81;
    BT9 temp;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        nums -= 1;
        temp = BT9(1 << (board[i][j] - '1'));
        row[i] |= temp, col[j] |= temp, room[(i / 3) * 3 + j / 3] |= temp;
      }
    }
    auto&& res = dfs(board, nums);
    cout << (res ? 1 : 0) << endl;
    return;
  }
};
// @lc code=end
