/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    map<char, int> res, pos;
    for (unsigned int i = 0; i < A[0].size(); i++) res[A[0][i]]++;
    for (unsigned int i = 1; i < A.size(); i++) {
      for (auto it = A[i].begin(); it != A[i].end(); it++) pos[*it]++;
      for (auto it = res.begin(); it != res.end();)
        if (pos[it->first] == 0)
          it = res.erase(it);
        else if (pos[it->first] < it->second) {
          it->second = pos[it->first];
          it++;
        } else
          it++;
      pos.clear();
    }
    vector<string> ans;
    for (auto it = res.begin(); it != res.end(); it++) {
      for (int j = 0; j < it->second; j++) {
        string s;
        s.push_back(it->first);
        ans.push_back(s);
      }
    }
    return ans;
  }
};

// @lc code=end
