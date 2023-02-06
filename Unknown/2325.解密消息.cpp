/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  string decodeMessage(string key, string message) {
    vector<int> dict(26, -1);
    int n = key.size();
    for (int i = 0, j = 0; i < n; i++) {
      if (key[i] == ' ' || dict[key[i] - 'a'] >= 0) continue;
      dict[key[i] - 'a'] = j++;
    }
    n = message.size();
    string res(n, ' ');
    for (int i = 0; i < n; i++) {
      if (message[i] == ' ') continue;
      res[i] = 'a' + dict[message[i] - 'a'];
    }
    return res;
  }
};
// @lc code=end
