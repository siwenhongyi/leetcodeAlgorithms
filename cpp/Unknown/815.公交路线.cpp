/*
 * Created by 张明利 on 2024年10月15日星期二 11:22:27
 */

/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

#include "head.h"
using namespace std;

// @lc code=start

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) return 0;
    int n = routes.size();
    set<int> rt[n];
    queue<int> q;
    unordered_set<int> v;
    vector<int> res(n, 1 << 30);
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < routes[i].size(); j++) {
        rt[i].insert(routes[i][j]);
        if (routes[i][j] == source) {
          res[i] = 1;
          v.insert(i);
          q.push(i);
        }
      }
    }
    while (!q.empty()) {
      auto qa = q.front();
      q.pop();
      for (int i = 0; i < n; i++) {
        if (i == qa || v.find(i) != v.end()) continue;
        for (auto& j : rt[i]) {
          if (rt[qa].find(j) != rt[qa].end() && res[qa] + 1 < res[i]) {
            res[i] = res[qa] + 1;
            v.insert(i);
            q.push(i);
            break;
          }
        }
      }
    }
    int ans = 1 << 30;
    for (int i = 0; i < n; i++) {
      cout << res[i] << endl;
      if (rt[i].find(target) != rt[i].end()) ans = min(ans, res[i]);
    }
    return ans == (1 << 30) ? -1 : ans;
  }
};

// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
