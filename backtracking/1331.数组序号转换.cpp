/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> arrayRankTransform(vector<int> arr) {
    if (arr.empty()) return {};
    vector<int> t(arr), res;
    map<int, int> book;
    sort(t.begin(), t.end());
    int i = 0, j, y, n;
    y = 1, n = arr.size();
    while (i < n) {
      j = i;
      while (j < n && t[i] == t[j]) {
        book[t[j++]] = y;
      }
      i = j;
      y++;
    }
    for (auto &it : arr) res.push_back(book[it]);
    // book.clear();
    return res;
  }
};
// @lc code=end
