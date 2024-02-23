/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 *
 * [1338] 数组大小减半
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;
    vector<vector<int>> pos;
    for (int& i : arr) mp[i]++;
    for (auto& i : mp) pos.push_back({i.first, i.second});
    sort(
        pos.begin(), pos.end(),
        [](const vector<int>& s, const vector<int>& t) { return s[1] > t[1]; });
    int n = arr.size(), m;
    m = n;
    vector<int> res;
    for (auto& i : pos) {
      res.push_back(i[0]);
      n -= i[1];
      if (n + n <= m) break;
    }
    return res.size();
  }
};
// @lc code=end
