/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (!nums1.size()) return res;
    map<int, int> book;
    for (unsigned int i = 0; i < nums2.size(); i++) book[nums2[i]] = i;
    unsigned int index, len = nums2.size();
    for (unsigned int i = 0; i < nums1.size(); i++) {
      index = book[nums1[i]];
      while (index < len && nums2[index] <= nums1[i]) index++;
      if (index != len)
        res.push_back(nums2[index]);
      else
        res.push_back(-1);
    }
    return res;
  }
};
// @lc code=end
