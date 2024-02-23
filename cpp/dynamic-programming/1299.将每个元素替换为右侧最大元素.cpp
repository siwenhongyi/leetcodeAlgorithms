/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int index = 0, i = 0, n = arr.size();
    auto it = arr.begin(), iter = arr.begin(), b = arr.begin();
    while (i != n - 1) {
      if (index <= i) {
        iter = max_element(b + i + 1, arr.end());
        index = iter - b;
        arr[i] = *iter;
      } else {
        arr[i] = arr[index];
      }
      i++;
      it++;
    }
    if (n) arr[n - 1] = -1;
    return arr;
  }
};
// @lc code=end
