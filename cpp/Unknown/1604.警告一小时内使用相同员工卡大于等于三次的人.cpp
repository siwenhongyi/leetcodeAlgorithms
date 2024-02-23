/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    map<string, set<int>> pos;
    int n = keyName.size(), tp;
    for (int i = 0; i < n; i++) {
      auto &&name = keyName[i], &&time_str = keyTime[i];
      tp = 60 * stoi(time_str.substr(0, 2)) + stoi(time_str.substr(3, 2));
      pos[name].insert(tp);
    }
    vector<string> res;
    int a, b, c;
    for (auto& it : pos) {
      a = b = c = -1;
      if (it.second.size() < 3) continue;
      for (auto& t : it.second) {
        if (a < 0) {
          a = t;
          continue;
        }
        if (b < 0) {
          b = t;
          continue;
        }
        c = t;
        if (c - a <= 60) {
          res.push_back(it.first);
          break;
        }
        a = b;
        b = c;
      }
    }
    return res;
  }
};
// @lc code=end
