/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    int a, b, l = 0, r = nums.size() - 1;
    int mid;
    a = b = -1;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (nums[mid] < target)
        l = mid + 1;
      else if (nums[mid] > target)
        r = mid - 1;
      else {
        a = b = mid;
        while (a >= 0 && nums[a] == target) a--;
        a++;
        while (b <= r && nums[b] == target) b++;
        b--;
        break;
      }
    }
    return {a, b};
  }
};
// @lc code=end
