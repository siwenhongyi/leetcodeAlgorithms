/*
 * @lc app=leetcode.cn id=1324 lang=cpp
 *
 * [1324] 竖直打印单词
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> printVertically(string s) {
    int ml = -1, n = s.size();
    int i, j;
    for (i = j = 0; i < n; i++) {
      if (s[i] == ' ') continue;
      j = i;
      while (j < n && s[j] != ' ') j++;
      ml = max(ml, int(s.substr(i, j - i).length()));
      i = j;
    }
    if (!ml) return {};
    vector<string> res(ml);
    for (i = j = 0; i < n; i++) {
      if (s[i] == ' ') {
        while (j <= ml - 1) res[j++] += ' ';
        j = 0;
        continue;
      }
      res[j++] += s[i];
    }
    for (auto t = res.begin(); t != res.end(); t++)
      while (t->back() == ' ') t->pop_back();
    return res;
  }
};

// @lc code=end
