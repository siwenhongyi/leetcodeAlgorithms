/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

#include "head.h"
using namespace std;
// @lc code=start
typedef pair<int, int> PII;

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<int> res;
    vector<PII> t;
    map<int, int> pos;
    for (auto& it : nums) pos[it]++;
    for (auto& it : pos) t.push_back(it);
    sort(t.begin(), t.end(), [](const PII& s, const PII& t) {
      if (s.second != t.second) return s.second < t.second;
      return s.first > t.first;
    });
    for (auto& it : t)
      for (int i = 0; i < it.second; i++) res.push_back(it.first);
    return res;
  }
};

// @lc code=end
