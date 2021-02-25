/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  vector<string> D = {"Billion ", "Million ", "Thousand ", ""},
                 big = {"Hundred ", "Twenty ",  "Thirty ", "Forty ", "Fifty ",
                        "Sixty ",   "Seventy ", "Eighty ", "Ninety "},
                 s = {"One ",       "Two ",      "Three ",   "Four ",
                      "Five ",      "Six ",      "Seven ",   "Eight ",
                      "Nine ",      "Ten ",      "Eleven ",  "Twelve ",
                      "Thirteen ",  "Fourteen ", "Fifteen ", "Sixteen ",
                      "Seventeen ", "Eighteen ", "Nineteen "};
  string num, res;

 public:
  void three(int st, int en, int key) {
    auto x = atoi(num.substr(st, en - st).c_str());
    if (x == 0) return;
    if (x >= 100) {
      res += s[x / 100 - 1];
      res += big[0];
      x %= 100;
    }
    if (x >= 20) {
      res += big[x / 10 - 1];
      if (x % 10) res += s[x % 10 - 1];

    } else if (x)
      res += s[x - 1];
    res += D[key];
  }
  string numberToWords(int t) {
    if (t == 0) return "Zero";
    num = to_string(t);
    if (t < 100) {
      three(0, num.size(), 3);
      res.pop_back();
      return res;
    }
    int n = num.size() / 3, m = num.size() % 3, i = 0;
    if (m) {
      three(0, m, 4 - n - 1);
      i = m;
    }
    while (n) {
      three(i, i + 3, 4 - n);
      i += 3;
      n--;
    }
    res.pop_back();
    return res;
  }
};

// @lc code=end
