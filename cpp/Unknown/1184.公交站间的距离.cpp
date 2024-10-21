/*
 * Created by 张明利 on 2024年10月15日星期二 11:15:02
 */

/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    int a = 0, b = 0, i = 0, n = distance.size();
    if (start > destination) swap(start, destination);
    do {
      a += distance[i];
      if (i >= start && i < destination) b += distance[i];
      i = (i + 1) % n;
    } while (i != 0);
    return min(b, a - b);
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
