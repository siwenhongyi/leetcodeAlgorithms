/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] 每种字符至少取 K 个
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int takeCharacters(string s, int k) {
    if (k == 0) return 0;
    int n = s.size();
    int a = count(s.begin(), s.end(), 'a');
    int b = count(s.begin(), s.end(), 'b');
    int c = count(s.begin(), s.end(), 'c');
    if (a < k || b < k || c < k) return -1;
    // abc 在区间允许最大值
    vector<int> cnt(3, 0), m = {a - k, b - k, c - k};
    int res = n;
    for (int l = 0, r = 0; r < n; r++) {
      auto&& index = s[r] - 'a';
      cnt[index]++;
      while (cnt[index] > m[index]) cnt[s[l++] - 'a']--;
      res = min(res, n - r + l - 1);
    }
    return res;
  }
};
// @lc code=end
