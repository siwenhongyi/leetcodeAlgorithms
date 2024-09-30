/*
 * Created by 张明利 on 9-30-2024, 4:51:30 PM
 */

/*
 * @lc app=leetcode.cn id=2073 lang=cpp
 *
 * [2073] 买票需要的时间
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    if (tickets.empty()) {
      return 0;
    }
    int m = tickets[0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> p;
    for (int i = 0; i < tickets.size(); i++) {
      p.push({i, 0});
    }
    int res = 0;
    while (p.size()) {
      auto tp = p.top();
      // cout << tp.first << ' ' << tp.second << ' ' << endl;
      p.pop();
      res++;
      tp.second++;
      if (tp.first % tickets.size() == k && tp.second == tickets[k]) {
        return res;
      }
      if (tp.second != tickets[tp.first % tickets.size()]) {
        p.push({tp.first + tickets.size(), tp.second});
      }
    }
    return res;
  }
};
// @lc code=end
