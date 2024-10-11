/*
 * Created by 张明利 on 2024年10月11日星期五 17:30:51
 */

/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  // 拓扑排序
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> mp;
    // 因为是线性的，所以可以这样。
    // 不会存在 c->a,b->a,a->d这样的例子
    for (const auto& p : paths) {
      mp[p[0]]--;
      mp[p[1]]++;
    }
    for (const auto& [k, v] : mp) {
      if (v == 1) return k;
    }
    return "";
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
