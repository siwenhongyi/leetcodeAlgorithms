/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<int> pos;

 public:
  Solution(vector<int>& nums) : pos(nums) {}

  vector<int> reset() { return pos; }

  vector<int> shuffle() {
    int n = pos.size(), index;
    if (n < 2) return pos;
    vector<int> res(pos);
    random_device rd;

    while (n >= 2) {
      index = rd() % n--;
      swap(res[n], res[index]);
    }
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
