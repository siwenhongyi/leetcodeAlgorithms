/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> ppos;
    vector<int> res;
    for (auto& c : p) ppos[c]++;
    int n = s.size();
    int left = 0, right = 0, length = p.size() - 1;
    while (right < n) {
      auto temp(ppos);
      while (right < n && temp.count(s[right])) {
        auto&& c = s[right];
        // cout << c << endl;
        if (temp[c]) {
          temp[c]--;
        } else {
          while (left < right && s[left] != c) {
            temp[s[left++]]++;
          }
          left++;
        }
        if (right - left == length) res.push_back(left);
        right++;
      }
      left = ++right;
    }
    return res;
  }
};
// @lc code=end
