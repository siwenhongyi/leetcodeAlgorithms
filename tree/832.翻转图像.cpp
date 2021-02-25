/*
* @lc app=leetcode.cn id=832 lang=cpp
*
* [832] 翻转图像
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int n = A.size();
    for (auto& it : A) {
      for (int i = 0; i <= n / 2; i++) {
        if (i == n / 2) {
          if (n % 2) it[i] = !it[i];
          break;
        }
        it[i] = !it[i];
        swap(it[i], it[n - i - 1]);
        it[i] = !it[i];
      }
    }
    return A;
  }
};
// @lc code=end

