/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

#include "head.h"
using namespace std;
// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    auto it = arr1.begin();
    for (unsigned int i = 0; i < arr2.size(); i++)
      for (unsigned int j = 0; j < arr1.size(); j++) {
        if (arr1[j] == arr2[i]) {
          int t = arr1[j];
          arr1[j] = *it;
          *it = t;
          it++;
        }
      }
    sort(it, arr1.end());
    return arr1;
  }
};

// @lc code=end
