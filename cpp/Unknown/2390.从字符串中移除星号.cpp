/*
 * Created by 张明利 on 2024年10月15日星期二 10:51:42
 */

/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] 从字符串中移除星号
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  string removeStars(string s) {
    // stack<char> st;
    deque<char> st;
    for (const auto& c : s) {
      if (c == '*') {
        if (st.size()) st.pop_back();
      } else {
        st.push_back(c);
      }
    }
    string res;
    while (st.size()) {
      res += st.front();
      st.pop_front();
    }
    // reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
