/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "head.h"
// @lc code=start
// class Solution {
//   int old_maxProfit(vector<int>& p) {
//     int n = p.size();
//     if (n < 2) return 0;
//     int m = p[0], res = 0;
//     for (int i = 1; i < n; i++) {
//       res = max(res, p[i] - m);
//       m = min(m, p[i]);
//     }
//     return res;
//   }

//  public:
//   int maxProfit(vector<int>& p) {
//     return old_maxProfit(p);
//     if (p.size() < 2) return 0;
//     stack<int> m;
//     int res = 0;
//     for (const auto& it : p) {
//       while (m.size() && m.top() > it) {
//         m.pop();
//       }
//       if (m.empty())
//         m.push(it);
//       else
//         res = max(res, it - m.top());
//     }
//     return res;
//   }
// };
// 2022。08.17 更新
class Solution {
 public:
  int maxProfit(vector<int>& p) {
    int n = p.size(), m = p[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
      res = max(res, p[i] - m);
      m = min(m, p[i]);
    }
    return res;
  }
};

// @lc code=end
