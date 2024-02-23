/*
 * @lc app=leetcode.cn id=2521 lang=cpp
 *
 * [2521] 数组乘积中的不同质因数数目
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  set<int> p;
  void helper() {
    vector<int> s(1024, 1);
    for (int i = 2; i <= 1000; i++) {
      if (s[i] == 0) continue;
      p.insert(i);
      for (int j = i + i; j <= 1000; j += i) s[j] = 0;
    }
  }

 public:
  int distinctPrimeFactors(vector<int>& nums) {
    set<int> res;
    unordered_map<int, set<int>> ca;
    helper();

    for (auto it : nums) {
      while (it != 1) {
        for (auto iter : p) {
          if (it % iter != 0) continue;
          res.insert(iter);
          while (it != 1 && it % iter == 0) {
            it = it / iter;
            cout << it << ' ';
          }
        }
      }
    }
    return res.size();
  }
};
// @lc code=end
