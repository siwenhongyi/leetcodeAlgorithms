/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> dfs(string s) {
    vector<int> res;
    vector<int> left, right;
    for (int i = 0; i < s.size(); i++)
      if (!isdigit(s[i])) {
        left = dfs(s.substr(0, i));
        right = dfs(s.substr(i + 1));
        for (auto it = left.begin(); it != left.end(); it++)
          for (auto iter = right.begin(); iter != right.end(); iter++)
            if (s[i] == '+')
              res.push_back(*it + *iter);
            else if (s[i] == '-')
              res.push_back(*it - *iter);
            else
              res.push_back(*it * *iter);
      }
    if (res.empty()) res.push_back(stoi(s));
    return res;
  }
  vector<int> diffWaysToCompute(string input) {
    if (input.empty()) return {};
    return dfs(input);
  }
};

// @lc code=end
