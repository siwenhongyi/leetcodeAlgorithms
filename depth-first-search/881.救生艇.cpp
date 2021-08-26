/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int res = 0;
    int st = 0, en = people.size() - 1;
    while (st <= en) {
      if (people[st] + people[en] <= limit) st++;
      res++;
      en--;
    }
    return res;
  }
};
// @lc code=end
