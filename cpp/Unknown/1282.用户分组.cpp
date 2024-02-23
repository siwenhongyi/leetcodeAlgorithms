/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> res;
    map<int, vector<vector<int>>> m;
    for (int i = 0; i < groupSizes.size(); i++) {
      auto&& it = m[groupSizes[i]];
      if (it.empty() || it.back().size() == groupSizes[i]) {
        it.push_back({i});
      } else {
        it.back().push_back(i);
      }
    }
    for (auto& it : m) {
      for (auto& iter : it.second) {
        res.push_back(iter);
      }
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
