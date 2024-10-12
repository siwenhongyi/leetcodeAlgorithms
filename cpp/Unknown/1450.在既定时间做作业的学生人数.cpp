/*
 * Created by 张明利 on 2024年10月11日星期五 19:02:56
 */

/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int res = 0;
    for (size_t i = 0; i < startTime.size(); i++) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) res++;
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
