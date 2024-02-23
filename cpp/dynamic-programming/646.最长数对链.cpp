/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    if (pairs.size() <= 1) return pairs.size();
    sort(pairs.begin(), pairs.end(),
         [](const vector<int> &s, const vector<int> &t) {
           return s.back() < t.back();
         });
    // dp做法 看了题解 原来可以贪心
    // 232ms 47.55% 17.2M 8429%
    // vector<int> res(pairs.size(), 1);
    // int m = 1;
    // for (int i = 1; i < pairs.size(); i++) {
    //	for (int j = 0; j < i; j++)
    //		if (pairs[j][1] < pairs[i][0])
    //			res[i] = max(res[i], res[j] + 1);
    //	m = max(m, res[i]);
    //}
    // return m;

    /*
    贪心做法 按照第二个数排序 依次向后找能装下的
    64ms 95.47%
    17.2M 84.29%
    */

    int res = 1, t = pairs.front().back();
    for (auto &i : pairs) {
      if (i.front() > t) {
        t = i.back();
        res++;
      }
    }

    return res;
  }
};

// @lc code=end
