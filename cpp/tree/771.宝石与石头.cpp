/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    int res = 0;
    for (auto& it : S) {
      if (J.find(it) != string::npos) res++;
    }
    return res;
  }
};
// @lc code=end
