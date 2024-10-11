/*
 * Created by 张明利 on 2024年10月11日星期五 11:38:38
 */

/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  // 堆解法 先一直走到没油为止
  // 然后在经过的加油站中按照从大到小的顺序加油
  // 如果加完了还不够就无解。
  // 加够了就把当前加油站加入备胎
  int minRefuelStops(int target, int now, vector<vector<int>>& stations) {
    int n = stations.size();
    stations.push_back({target, target + 1});
    priority_queue<int> q;
    int res = 0;
    for (int i = 0; i <= n; i++) {
      if (now < stations[i][0]) {
        while (q.size() && now < stations[i][0]) {
          now += q.top();
          res++;
          q.pop();
        }
        if (now < stations[i][0]) {
          return -1;
        }
      }
      q.push(stations[i][1]);
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
