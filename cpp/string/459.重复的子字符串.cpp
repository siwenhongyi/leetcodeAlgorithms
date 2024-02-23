/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int size = s.size();
    if (size <= 1) return false;
    char head = s[0];
    int len = 1;
    for (int i = 1; i < size; i++) {
      if (s[i] == head) {
        int j = i, k = 0;
        while (j < size && s[j] == s[k]) {
          j++;
          k++;
          if (k == len) k = 0;
        }
        if (j == size && !k)
          return true;
        else
          len = i + 1;
      } else {
        len++;
      }
    }
    return false;
  }
};

// @lc code=end
