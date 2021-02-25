/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

#include "head.h"
using namespace std;
// @lc code=start
typedef pair<char, int> pp;

class Solution {
 public:
  string frequencySort(string s) {
    string t;
    vector<pp> res;
    unordered_map<char, int> pos;
    for (auto& i : s) pos[i]++;
    for (auto& i : pos) res.push_back(i);
    sort(res.begin(), res.end(),
         [](const pp& s, const pp& t) { return s.second > t.second; });
    int i, n;
    char tt;
    for (auto& it : res) {
      tt = it.first;
      i = 0;
      n = it.second;
      while (i < n) {
        t.push_back(tt);
        i++;
      }
    }
    return t;
  }
};

// @lc code=end
