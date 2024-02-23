/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  char slowestKey(vector<int>& re, string keys) {
    vector<int> res(26, 0);
    re.insert(re.begin(), 0);
    for (int i = 1; i < re.size(); i++) {
      res[keys[i - 1] - 'a'] = max(res[keys[i - 1] - 'a'], re[i] - re[i - 1]);
    }
    int x = *max_element(res.begin(), res.end());
    for (int i = 25; i >= 0; i--)
      if (res[i] == x) return i + 'a';
    return 'a';
  }
};

// @lc code=end
