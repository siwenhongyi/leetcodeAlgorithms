/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品 Easy (76.75%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& v1,
                                        vector<vector<int>>& v2) {
    vector<int> cnt(10010);
    for (int i = 0; i < v1.size(); i++) {
      cnt[v1[i][0]] = v1[i][1];
    }
    for (int i = 0; i < v2.size(); i++) {
      cnt[v2[i][0]] += v2[i][1];
    }
    int c = 0;
    for (int i = 1; i <= 1000; i++) {
      c += cnt[i] > 0;
    }
    vector<vector<int>> ans(c);
    int k = 0;
    for (int i = 1; i <= 1000; i++) {
      if (cnt[i]) {
        ans[k].push_back(i), ans[k].push_back(cnt[i]);
        k++;
      }
    }
    return ans;
  }
};
// @lc code=end
