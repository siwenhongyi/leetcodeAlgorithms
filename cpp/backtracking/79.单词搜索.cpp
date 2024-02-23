/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  int n, m, word_size;
  vector<vector<char>> mat;
  unordered_set<int> visited;
  string target;
  static constexpr array fx = {-1, 1, 0, 0};
  static constexpr array fy = {0, 0, -1, 1};
  bool dfs(int i, int j, int k) {
    if (k == word_size) return true;
    visited.insert(i * m + j);
    bool res = false;
    for (int index = 0; index < 4 && !res; index++) {
      auto &&new_x = i + fx[index], &&new_y = j + fy[index];
      if (new_x < 0 || new_y < 0 || new_x == n || new_y == m) continue;
      if (mat[new_x][new_y] != target[k + 1] ||
          visited.count(new_x * m + new_y))
        continue;
      res = dfs(new_x, new_y, k + 1);
    }
    visited.erase(i * m + j);
    return res;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    bool res = false;
    n = board.size(), m = board[0].size(), word_size = word.size() - 1;
    // if mat had moew target.back char than target.front
    // search starrt with back will be faster and less dfs count
    int h = 0;
    for (const vector<char>& row : board)
      for (const char& c : row) {
        if (c == word[0])
          h += 1;
        else if (c == word.back())
          h -= 1;
      }
    if (h > 0) reverse(word.begin(), word.end());
    mat.swap(board), target.swap(word);
    for (int i = 0; i < n && !res; i++) {
      for (int j = 0; j < m && !res; j++) {
        if (mat[i][j] == target[0]) {
          res = dfs(i, j, 0);
        }
      }
    }
    return res;
  }
};
// @lc code=end
