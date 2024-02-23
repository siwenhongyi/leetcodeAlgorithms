/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> mp;
    vector<vector<string>> res;
    for (auto& s : strs) {
      auto tmp = s;
      sort(s.begin(), s.end());
      if (mp.find(s) == mp.end()) {
        mp[s] = res.size();
        res.push_back({tmp});
      } else {
        res[mp[s]].push_back(tmp);
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
