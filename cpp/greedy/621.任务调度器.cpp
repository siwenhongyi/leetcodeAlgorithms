/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> ch(26, 0);
    int i = 0, res = 0;
    for (auto& it : tasks) ch[it - 'A']++;
    sort(ch.begin(), ch.end());
    while (ch[25]) {
      i = 0;
      while (i <= n) {
        if (ch[25] == 0) break;
        if (i <= 25 && ch[25 - i] > 0) ch[25 - i]--;
        res++;
        i++;
      }
      sort(ch.begin(), ch.end());
    }
    return res;
  }
};
// @lc code=end
