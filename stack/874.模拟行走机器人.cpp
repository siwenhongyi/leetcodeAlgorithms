/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0, y = 0, flag = 1;
    int res = 0;
    set<vector<int>> pos;
    for (auto& i : obstacles) pos.insert(i);
    for (auto i : commands) {
      if (i == -1) {
        flag++;
        if (flag == 5) flag = 1;
      } else if (i == -2) {
        flag--;
        if (!flag) flag = 4;
      } else {
        while (i--) {
          int a = x, b = y;
          switch (flag) {
            case 1:
              b++;
              break;
            case 2:
              a++;
              break;
            case 3:
              b--;
              break;
            case 4:
              a--;
              break;
            default:
              break;
          }
          vector<int> t = {a, b};
          auto it = pos.find(t);
          if (it != pos.end())
            break;
          else {
            x = a;
            y = b;
          }
        }
        if (x * x + y * y > res) res = x * x + y * y;
      }
    }
    return res;
  }
};

// @lc code=end
