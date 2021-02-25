/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    if (barcodes.size() <= 2) return barcodes;
    sort(barcodes.begin(), barcodes.end());
    vector<int> res(1, barcodes[0]);
    barcodes.erase(barcodes.begin());
    int n = barcodes.size();
    auto it = barcodes.begin();
    int i = 0;
    while (i < barcodes.size())
      if (barcodes[i] != res.back())
        res.push_back(barcodes[i++]);
      else {
        auto it = barcodes.end() - 1;
        while (it != barcodes.begin() + i && *it == res.back()) it--;
        if (it != barcodes.begin() + i) {
          res.push_back(*it);
          barcodes.erase(it);
        } else {
          res.push_back(res.front());
          res.erase(res.begin());
        }
      }
    return res;
  }
};
// @lc code=end
