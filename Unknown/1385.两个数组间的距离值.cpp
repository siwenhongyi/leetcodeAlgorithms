/*
* @lc app=leetcode.cn id=1385 lang=cpp
*
* [1385] 两个数组间的距离值
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0, n = arr2.size();
        for (auto &it:arr1) {
            bool b = true;
            for (int i = 0; i < n; i++) {
                if (abs(it - arr2[i]) <= d) {
                    b = false;
                    break;
                }
            }
            res += b;
        }
        return res;
    }
};

// @lc code=end

