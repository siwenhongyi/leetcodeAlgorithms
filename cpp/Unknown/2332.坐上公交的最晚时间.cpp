/*
 * Created by 张明利 on 2024年10月15日星期二 20:07:22
 */

/*
 * @lc app=leetcode.cn id=2332 lang=cpp
 *
 * [2332] 坐上公交的最晚时间
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int latestTimeCatchTheBus(vector<int>& b, vector<int>& c, int m) {
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    set<int> st;
    for (const auto& it : c) st.insert(it);

    int i = 0, j = 0, n = b.size(), cm = c.size();
    int res = -1, cnt, curr;
    while (i < n) {
      cnt = 0, curr = b[i];
      while (cnt < m && j < cm && c[j] <= b[i]) {
        if (st.find(c[j] - 1) == st.end()) res = c[j] - 1;
        cnt++, j++;
      }
      if (cnt < m) {
        while (st.find(curr) != st.end()) curr--;
        res = max(res, curr);
      }
      i++;
    }
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
