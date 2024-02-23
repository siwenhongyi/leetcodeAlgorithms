/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  double trimMean(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int skip = n * 0.05, sum = 0;
    for (int i = skip; i < n - skip; i++) {
      sum += arr[i];
    }
    return sum / double(n - 2 * skip);
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
