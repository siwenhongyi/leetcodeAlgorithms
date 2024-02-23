/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (nums1.size() == 0 || nums2.size() == 0) return res;
    if (nums1.size() < nums2.size()) nums1.swap(nums2);
    map<int, int> pos;
    for (auto& i : nums1) pos[i]++;
    for (auto& i : nums2)
      if (pos[i]) {
        res.push_back(i);
        pos[i]--;
      }
    return res;
  }
};
// @lc code=end
