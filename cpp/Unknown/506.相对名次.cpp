/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    map<int, int, greater<int>> book;
    vector<string> res(nums.size());
    string ans[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    int cou = 0;
    for (unsigned int i = 0; i < nums.size(); i++) book[nums[i]] = i;

    int index = 4;
    for (auto it = book.begin(); it != book.end(); it++) {
      if (cou < 3)
        res[it->second] = ans[cou++];
      else {
        res[it->second] = to_string(index++);
      }
    }
    return res;
  }
};

// @lc code=end
