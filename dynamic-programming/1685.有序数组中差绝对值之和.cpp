/*
 * @lc app=leetcode.cn id=1685 lang=cpp
 *
 * [1685] 有序数组中差绝对值之和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& pos) {
    int n = pos.size();
    int fr = 0, ba = 0;
    vector<int> res(n, 0);
    long long int a, b;
    for (int i = 0; i < n; i++) ba += pos[i];
    for (int i = 0; i < n; i++) {
      ba -= pos[i];
      if (i && pos[i] == pos[i - 1])
        res[i] = res[i - 1];
      else {
        res[i] = ba - pos[i] * (n - i - 1);
        res[i] += pos[i] * i - fr;
      }
      fr += pos[i];
    }
    return res;
  }
};
// @lc code=end
