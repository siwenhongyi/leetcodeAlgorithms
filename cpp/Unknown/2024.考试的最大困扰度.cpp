/*
 * Created by 张明利 on 2024年10月11日星期五 19:07:19
 */

/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int count(string s, int k, char ch) {
    int n = s.length();

    int maxlen = 0, bad = 0;  // count of opposite parity character

    int i = 0, j = 0;
    while (j < n) {
      if (s[j] != ch)
        bad++;  // check if we are acquiring a bad character at rear end

      while (i <= j && bad > k) {
        char cur = s[i];
        if (cur != ch)
          bad--;  // releasing bad characters acquired from front end
        i++;
      }

      maxlen = max(maxlen, j - i + 1);
      j++;
    }
    return maxlen;
  }
  // 滑动窗口
  int maxConsecutiveAnswers(string s, int k) {
    return max(count(s, k, 'T'),
               count(s, k, 'F'));  // max number of consecutive 'T's or 'F's
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
