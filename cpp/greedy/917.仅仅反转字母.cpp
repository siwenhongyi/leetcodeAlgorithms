/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string reverseOnlyLetters(string S) {
    if (S.size() < 2) return S;
    int l = 0, r = S.size() - 1;
    bool t;
    while (l < r) {
      t = (S[l] >= 'a' && S[l] <= 'z') || (S[l] >= 'A' && S[l] <= 'Z');
      while (!t && l < r) {
        l++;
        t = (S[l] >= 'a' && S[l] <= 'z') || (S[l] >= 'A' && S[l] <= 'Z');
      }
      t = (S[r] >= 'a' && S[r] <= 'z') || (S[r] >= 'A' && S[r] <= 'Z');
      while (!t && l < r) {
        r--;
        t = (S[r] >= 'a' && S[r] <= 'z') || (S[r] >= 'A' && S[r] <= 'Z');
      }
      if (l < r) {
        swap(S[l], S[r]);
        l++;
        r--;
      }
    }
    return S;
  }
};
// @lc code=end
