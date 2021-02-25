/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canChoose(vector<vector<int>>& mat, vector<int>& nums) {
    int n = nums.size();
    int a = 0;
    int nn = mat.size();
    set<int> nice;
    for (int i = 0; i < n && a < nn; i++) {
      if (nums[i] == mat[a][0]) {
        int j = i;
        while (j < n && j - i < mat[a].size() && nums[j] == mat[a][j - i]) j++;
        if (j - i == mat[a].size()) {
          nice.insert(a++);
          i = j - 1;
        }
      }
    }
    return nice.size() == nn;
  }
};
// @lc code=end
