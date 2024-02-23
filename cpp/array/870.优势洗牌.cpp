/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> advantageCount(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    vector<int> res;
    int n = A.size();
    for (int i = 0; i < n; i++) {
      auto it = upper_bound(A.begin(), A.end(), B[i]);
      if (it != A.end()) {
        res.push_back(*it);
      } else {
        res.push_back(A.front());
        it = A.begin();
      }
      A.erase(it);
    }
    return res;
  }
};
// @lc code=end
