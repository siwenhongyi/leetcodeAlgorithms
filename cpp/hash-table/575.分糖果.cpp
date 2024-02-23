/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int distributeCandies(vector<int>& candyType) {
    return min(unordered_set<int>(candyType.begin(), candyType.end()).size(),
               candyType.size() / 2);
    unordered_set<int> res;
    int can = candyType.size() / 2;
    for (auto& it : candyType) {
      res.insert(it);
    }
    return min(int(res.size()), can);
  }
};
// @lc code=end
