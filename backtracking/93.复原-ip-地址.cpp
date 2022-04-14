/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> res;
  vector<int> path;
  void dfs(const string& s, int index) {
    if (index == s.size()) {
      if (path.size() == 4) {
        string ip = "";
        for (int i = 0; i < 4; ++i) {
          if (i) ip += '.';
          ip += to_string(path[i]);
        }
        res.push_back(ip);
      }
      return;
    }
    if (s[index] == '0') {
      path.push_back(0);
      dfs(s, index + 1);
      path.pop_back();
    } else {
      int num = 0;
      for (int i = index; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
        if (num > 255) break;
        path.push_back(num);
        dfs(s, i + 1);
        path.pop_back();
      }
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    if (n == 0 || n > 12) return {};
    dfs(s, 0);
    return res;
  }
};
// @lc code=end
