/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int res = 0;
    int x = sequence.find(word), n = word.size();
    while (x != string::npos) {
      int t = 0;
      while (x < sequence.size()) {
        if (sequence.substr(x, n) == word) {
          t++;
          x += n;
        } else
          break;
      }
      res = max(res, t);
      sequence = sequence.substr(x);
      x = sequence.find(word);
    }
    return res;
  }
};

// @lc code=end
