/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  int strStr(string s, string t) {
    int sn = s.size(), tn = t.size(), i, j;
    bool ok;
    if (!tn) return 0;
    vector pos(26, -1);
    for (i = 0; i < tn; i++) {
      auto&& curr = pos[t[i] - 'a'];
      curr = i;
    }
    int l, r;
    i = j = 0;
    while (i < sn) {
      j = 0;
      if (s[i] == t[j]) {
        l = i, r = j;
        while (l < sn && r < tn && s[l] == t[r]) l++, r++;
        if (r == tn) return i - j;
      }
      if (i + tn >= sn) break;
      auto&& next_index = pos[s[i + tn] - 'a'];
      i += tn - next_index;
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution solution;
  // any test cases
  map<string, string> test_cases = {{"hello", "ll"},
                                    {"aaaaa", "bba"},
                                    {"", "a"},
                                    {"a", "a"},
                                    {"abc", "abc"},
                                    {"mississippi", "issi"},
                                    {"mississippi", "issip"}};
  for (auto&& [s, t] : test_cases) {
    long long ExpectedAnswer = s.find(t);
    if (ExpectedAnswer == string::npos) ExpectedAnswer = -1;
    cout << "Testcase\n"
         << s << "\n"
         << t << "\n"
         << "Answer\n"
         << solution.strStr(s, t) << "\n"
         << "Expected Answer\n"
         << ExpectedAnswer << endl;
  }
  return 0;
}
