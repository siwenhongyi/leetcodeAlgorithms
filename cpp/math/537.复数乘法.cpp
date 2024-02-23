/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    int v, e, c, d;
    int index = a.find_first_of('+'), index_x = b.find_first_of('+');
    string t(a.begin(), a.begin() + index);
    string x(b.begin(), b.begin() + index_x);
    v = atoi(t.c_str());
    c = atoi(x.c_str());
    t.clear();
    x.clear();
    t.insert(t.end(), a.begin() + index + 1, a.end() - 1);
    x.insert(x.end(), b.begin() + index_x + 1, b.end() - 1);
    e = atoi(t.c_str());
    d = atoi(x.c_str());

    string res = to_string(v * c - e * d);
    res.push_back('+');
    res += to_string(v * d + e * c);
    res.push_back('i');
    return res;
  }
};
// @lc code=end
