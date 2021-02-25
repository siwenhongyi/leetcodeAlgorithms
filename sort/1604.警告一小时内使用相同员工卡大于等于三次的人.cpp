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
    int n = keyName.size();
    for (int i = 0; i < n; i++) {
      int t = stoi(keyTime[i].substr(0, 2)) * 60 + stoi(keyTime[i].substr(3));
      pos[keyName[i]].insert(t);
    }
    vector<string> res;
    vector<int> tme;
    for (auto& it : pos) {
      auto f = it.first;
      auto s = it.second;
      tme.clear();
      for (auto& iter : s) {
        tme.push_back(iter);
        if (tme.size() == 3) {
          if (tme[2] - tme[0] <= 60) {
            res.push_back(f);
            break;
          } else
            tme.erase(tme.begin());
        }
      }
    }
    return res;
  }
};

// @lc code=end
