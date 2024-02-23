/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> res;
    for (auto& i : A) res.push_back(i * i);
    sort(res.begin(), res.end());
    return res;
  }
};

// @lc code=end
