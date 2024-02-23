/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> uncommonFromSentences(string A, string B) {
    if (A.empty() && B.empty()) return {};
    A.push_back(' ');
    B.push_back(' ');
    A += B;
    vector<string> res;
    int index, i, j;
    map<string, int> pos;
    int n = A.size();
    index = 0;
    while (index < n) {
      if (A[index] == ' ') {
        index++;
        continue;
      }
      i = index;
      while (i < n && A[i] != ' ') i++;
      pos[A.substr(index, i - index)]++;
      index = i;
    }
    for (auto& s : pos)
      if (s.second == 1) res.push_back(s.first);
    return res;
  }
};

// @lc code=end
