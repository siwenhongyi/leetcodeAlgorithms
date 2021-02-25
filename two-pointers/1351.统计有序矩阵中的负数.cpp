/*
* @lc app=leetcode.cn id=1351 lang=cpp
*
* [1351] 统计有序矩阵中的负数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& arr) {
        if (arr.empty())
            return 0;
        int n = arr.size(), m = arr[0].size();
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i][m - 1] >= 0)
                break;
            for (int j = m - 1; j >= 0; j--) {
                if (arr[i][j] < 0)
                    res++;
                else
                    break;
            }
        }
        return res;
    }
};
// @lc code=end

