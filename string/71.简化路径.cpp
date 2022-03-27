/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    path += '/';
    vector<string> st;
    int n = path.size(), index = 1, t = 0;
    while (index < n) {
      if (path[index] == '/') {
        if (index != t + 1) {
          auto&& s = path.substr(t + 1, index - t - 1);
          if (s == "..") {
            if (!st.empty()) st.pop_back();
          } else if (s == ".")
            ;
          else
            st.emplace_back(s);
        }
        t = index;
      }
      index++;
    }
    string res("/");
    n = st.size();
    for (index = 0; index < n; index++) {
      if (index) res += '/';
      res += st[index];
    }
    return res;
  }
};
// @lc code=end
