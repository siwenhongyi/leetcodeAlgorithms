/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  string reformat(string str) {
    string d, s;
    for (auto& it : str) {
      if (it >= 'a' && it <= 'z')
        s.push_back(it);
      else
        d.push_back(it);
    }
    int a = s.size(), b = d.size();
    if (abs(a - b) > 1) return "";
    string res;
    if (a < b) {
      swap(a, b);
      s.swap(d);
    }
    int i = 0;
    while (i < b) {
      res.push_back(s[i]);
      res.push_back(d[i++]);
    }
    if (i < a) res.push_back(s.back());
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  cout << Solution().reformat("a0b1c2") << endl;

  cout << Solution().reformat("covid2019") << endl;
  cout << Solution().reformat("ab123") << endl;
  return 0;
}
