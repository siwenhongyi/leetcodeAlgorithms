/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  string countAndSay(int n) {
    if (!n) return "";
    string a, b;
    a.push_back('1');
    for (int i = 1; i < n; i++) {
      char c = a[0];
      int count = 1;
      b.clear();
      for (unsigned int i = 1; i < a.size(); i++) {
        if (a[i] == c)
          count++;
        else {
          b.push_back('0' + count);
          b.push_back(c);
          c = a[i];
          count = 1;
        }
      }
      b.push_back('0' + count);
      b.push_back(c);
      a = b;
    }
    return a;
  }
};

// @lc code=end
