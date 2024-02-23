/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canFinish(int n, vector<vector<int>>& ed) {
    unordered_map<int, unordered_set<int>> out;
    unordered_map<int, int> in;
    for (int i = 0; i < n; in[i++])
      ;
    for (auto it : ed) {
      out[it[0]].insert(it[1]);
      in[it[1]]++;
    }
    bool flag = false;
    while (n) {
      flag = false;
      for (auto& it : in) {
        if (it.second == 0) {
          flag = true;
          auto v = it.first;
          for (auto& iter : out[v]) {
            in[iter]--;
          }
          in.erase(v);
          n--;
          break;
        }
      }
      if (!flag) return false;
    }
    return true;
  }
};

// @lc code=end
