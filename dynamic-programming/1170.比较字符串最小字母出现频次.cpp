/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> a, b, res;
    for (auto& it : queries)
      a.push_back(
          count(it.begin(), it.end(), *min_element(it.begin(), it.end())));
    for (auto& it : words)
      b.push_back(
          count(it.begin(), it.end(), *min_element(it.begin(), it.end())));
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = 0; j < m; j++)
        if (a[i] < b[j]) t++;
      res.push_back(t);
    }
    return res;
  }
};

// @lc code=end
