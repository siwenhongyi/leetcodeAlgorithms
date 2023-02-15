/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  using pii = pair<int, int>;
  map<char, pii> pos;

 public:
  string alphabetBoardPath(string target) {
    int row, col;
    for (int i = 0; i < 26; i++) {
      row = i / 5, col = i % 5;
      pos['a' + i] = {row, col};
    }
    row = col = 0;
    string res, a, b;
    int shu_c, heng_c;
    for (auto& c : target) {
      auto&& [x, y] = pos[c];
      a.clear(), b.clear();
      auto shu_c = row - x, heng_c = col - y;
      while (shu_c > 0) {
        a.push_back('U');
        shu_c--;
      }
      while (shu_c < 0) {
        shu_c++;
        a.push_back('D');
      }
      while (heng_c > 0) {
        b.push_back('L');
        heng_c--;
      }
      while (heng_c < 0) {
        heng_c++;
        b.push_back('R');
      }
      if (c == 'z') {
        res += b;
        res += a;
      } else {
        res += a;
        res += b;
      }
      res.push_back('!');
      row = x, col = y;
    }
    return res;
  }
};

// @lc code=end
