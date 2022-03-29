/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  unordered_map<int, int> nums;
  bool check() {
    for (auto& it : nums)
      if (it.second < 0) return false;
    return true;
  }

 public:
  string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    int l = 0, r = t.size(), n = s.size();
    for (auto& it : t) nums[it]--;
    auto&& en = nums.end();
    for (int i = 0; i < r; i++)
      if (nums.find(s[i]) != en) nums[s[i]]++;
    bool flag = check();
    int start = -1, length = 1 << 28, poped = 0;
    while (l < n) {
      if (flag) {
        if (r - l < length) start = l, length = r - l;
        if (nums.find(s[l]) != en) {
          nums[s[l]]--;
          flag = check();
        }
        l++;
      } else {
        if (r == n) break;
        while (r < n && nums.find(s[r]) == en) r++;
        if (r < n) {
          nums[s[r++]]++;
          flag = check();
        }
      }
    }
    return start < 0 ? "" : s.substr(start, length);
  }
};
// @lc code=end
