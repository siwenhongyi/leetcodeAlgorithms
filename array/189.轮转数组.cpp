/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组 Medium (44.26%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  void rotate_reverse(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
  void rotate_gcd(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    int cnt = gcd(n, k);
    int curr, pre;
    for (int i = 0, j; i < cnt; i++) {
      curr = i, pre = nums[i];
      do {
        j = (curr + k) % n;
        swap(pre, nums[j]);
        curr = j;
      } while (curr != i);
    }
  }

 public:
  void rotate(vector<int>& nums, int k) {
    // rotate_reverse(nums, k);
    rotate_gcd(nums, k);
  }
};
// @lc code=end
