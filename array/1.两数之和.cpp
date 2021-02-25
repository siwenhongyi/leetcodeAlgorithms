/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> map1;
    vector<int> res;
    vector<int>::iterator iter = nums.begin();
    vector<int>::iterator first = nums.begin();
    int index;
    while (iter != nums.end()) {
      // if (map1.count(*iter) == 0)
      if (map1.find(*iter) == map1.end()) {
        index = distance(first, iter);
        map1[target - *iter] = index;
        // map1.insert(make_pair(target-*iter, index));
      } else {
        res.insert(res.begin(), map1.find(*iter)->second);
        index = distance(first, iter);
        res.insert(res.end(), index);
      }
      iter++;
    }
    return res;
  }
};
// @lc code=end
