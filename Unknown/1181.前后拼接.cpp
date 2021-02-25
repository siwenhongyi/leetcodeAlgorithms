/*
 * @lc app=leetcode.cn id=1181 lang=cpp
 *
 * [1181] 前后拼接
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> beforeAndAfterPuzzles(vector<string>& s) {
    if (s.empty()) return {};
    vector<int> x, y;
    for (auto& i : s) {
      x.push_back(i.find_first_of(' '));
      y.push_back(i.find_last_of(' '));
    }
    set<string> res;
    int n = s.size();
    int a, b, inf = string::npos;
    for (int i = 0; i < n; i++) {
      a = y[i];
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        b = x[j];
        if (a == inf && b == inf) {
          if (s[i] == s[j]) res.insert(s[i]);
        } else if (a == inf && b != inf) {
          if (s[i] == s[j].substr(0, b)) res.insert(s[j]);
        } else if (a != inf && b == inf) {
          if (s[i].substr(a + 1) == s[j]) res.insert(s[i]);
        } else {
          // cout << s[i].substr(a+1) << endl << s[j].substr(0, b);
          if (s[i].substr(a + 1) == s[j].substr(0, b)) {
            string t = s[i];
            t += s[j].substr(b);
            res.insert(t);
          }
        }
      }
    }
    return vector<string>(res.begin(), res.end());
  }
};

// @lc code=end
