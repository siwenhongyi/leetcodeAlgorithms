/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int countLargestGroup(int n) {
    int t = 0, x = n, pre = 0;
    map<int, int> ret;
    while (x) t++, x /= 10;
    vector<int> res(t, 0);
    // res[t - 1] = 1;
    x = 1;
    while (x <= n) {
      if (++res[t - 1] == 10) {
        pre = 0;
        for (int i = t - 1; i >= 0; i--) {
          if (res[i] == 10 && i != 0) res[i - 1]++, res[i] = 0;
          pre += res[i];
        }
      } else
        pre += 1;
      ret[pre]++;
      x++;
    }
    int m = ret.begin()->second, cou = 0;
    for (auto& it : ret)
      if (it.second == m)
        cou++;
      else if (it.second > m)
        cou = 1, m = it.second;
    return cou;
  }
};

// @lc code=end
