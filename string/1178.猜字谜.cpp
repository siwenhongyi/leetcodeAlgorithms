/*
 * @lc app=leetcode.cn id=1178 lang=cpp
 *
 * [1178] 猜字谜
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findNumOfValidWords(vector<string>& words,
                                  vector<string>& puzzles) {
    int n = words.size(), m = puzzles.size(), i, j, k;
    unordered_map<int, int> book;
    vector<int> res(m, 0);
    for (auto& it : words) {
      k = 0;
      for (auto& ch : it) {
        k |= 1 << (ch - 'a');
      }
      book[k]++;
    }
    i = 0;
    for (auto& it : puzzles) {
      k = 0;
      for (auto& ch : it) k |= 1 << (ch - 'a');
      j = k;
      while (j) {
        if (j >> (it[0] - 'a') & 1) res[i] += book[j];
        j = j - 1 & k;
        /*
        -1 是遍历所有小的数字 也就是子集
         &k 是保证 原来有的字幕可能有 但是没有的字幕肯定不要出现
        */
      }
      i++;
    }
    return res;
  }
};

// @lc code=end
