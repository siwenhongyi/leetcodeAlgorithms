/*
 * @lc app=leetcode.cn id=1156 lang=cpp
 *
 * [1156] 单字符重复子串的最大长度
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxRepOpt1(string text) {
    if (text.size() == 0) return 0;
    int res = 0;
    for (int i = 0; i < text.size();) {
      int j = i;
      int len = 0;
      int x;
      while (j < text.size() && text[j] == text[i]) {
        len++;
        j++;
      }
      int index = j;
      if (j + 1 < text.size()) {
        int k = 0;
        int flag = 1;
        while (k < i) {
          if (text[k] == text[i]) {
            x = k;
            k = -1;
            flag = 0;
            break;
          }
          k++;
        }
        if (flag) {
          k = text.size() - 1;
          while (k > j + 1) {
            if (text[k] == text[i]) {
              x = k;
              k = -1;
              break;
            }
            k--;
          }
        }
        if (k == -1) {
          int y = j;
          swap(text[y], text[x]);
          len++;
          j++;
          while (j < text.size() && text[j] == text[i]) {
            len++;
            j++;
          }
          swap(text[y], text[x]);
        }
      } else if (j == text.size()) {
        int k = 0;
        while (k < i)
          if (text[k] == text[i])
            break;
          else
            k++;
        if (k != i) {
          len++;
          j++;
        }
      }
      if (len > res) res = len;
      i = index;
    }
    return res;
  }
};
// @lc code=end
