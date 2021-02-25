/*
 * @lc app=leetcode.cn id=1182 lang=cpp
 *
 * [1182] 与目标颜色间的最短距离
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> shortestDistanceColor(vector<int>& v, vector<vector<int>>& q) {
    map<pair<int, int>, int> book;
    vector<int> res;
    int n = v.size();
    for (auto& i : q) {
      auto pp = make_pair(i.front(), i.back());
      if (book[pp]) {
        res.push_back(book[pp]);
        continue;
      }
      int x = i.front(), y = i.back();
      int flag = -1;
      flag = -1;
      int j, k, len;
      j = k = x;
      len = 0;
      while (j >= 0 || k <= n) {
        if ((j >= 0 && v[j] == y) || (k < n && v[k] == y)) {
          flag = len;
          break;
        }
        j--;
        k++;
        len++;
      }
      res.push_back(flag);
      book[pp] = flag;
    }
    return res;
  }
};

// @lc code=end
