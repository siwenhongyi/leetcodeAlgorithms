/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 *
 * [1177] 构建回文串检测
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    int n = s.size(), i = 0, j, k, odd;
    vector<bool> res;
    array<int, 26> *p, cou = {};
    p = new array<int, 26>[n + 1];
    p[0] = cou;
    while (i < n) {
      cou[s[i] - 'a']++;
      p[++i] = cou;
    }
    for (auto &q : queries) {
      odd = 0;
      if (q.back() >= 13)
        res.push_back(true);
      else {
        i = q.front();
        j = q[1] + 1;
        k = q.back() * 2 + ((j - i) % 2);
        for (int t = 0; t < 26; t++) {
          odd += (p[j][t] - p[i][t]) % 2;
        }
        res.push_back(k >= odd);
      }
    }
    delete[] p;
    return res;
  }
};

// @lc code=end
