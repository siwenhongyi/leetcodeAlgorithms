/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include "head.h"
using namespace std;
// @lc code=start
// class Solution {
//  public:
//   void nextPermutation(vector<int>& nums) {
//     if (nums.size() <= 1) return;
//     bool t = false;
//     int index = nums.size() - 2;
//     while (index >= 0 && nums[index] >= nums[index + 1]) index--;
//     if (index >= 0) {
//       int j = nums.size() - 1;
//       while (j >= 0 && nums[j] <= nums[index]) j--;
//       swap(nums[index], nums[j]);
//     }
//     reverse(nums.begin() + index + 1, nums.end());
//   }
// };

// 2022-06-16 15:13:00 更新`
class Solution {
 private:
  /* data */
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return;
    int i = n - 2, j = n - 1;
    for (; i >= 0; i--) {
      if (nums[i] >= nums[i + 1]) continue;
      while (j > i && nums[j] <= nums[i]) j--;
      swap(nums[i++], nums[j]);
      j = n - 1;
      while (i < j) {
        swap(nums[i++], nums[j--]);
      }
      return;
    }
    reverse(nums.begin(), nums.end());
    return;
  }
};

// @lc code=end
