/*
* @lc app=leetcode.cn id=1504 lang=cpp
*
* [1504] 统计全 1 子矩形
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if (mat.empty())
            return 0;
        int n = mat.size(), m = mat[0].size();
        int res = 0, count = 0;
        int i, j, k;
        for(i = 0; i < n; i++) {
            count = 0;
            for (j = i; j < n; j++)
                for (k = 0; k < m; k++) {
                    if (mat[j][k] == 1)
                        count = k == 0 ? 1 : count + 1;
                    else
                        count = 0;
                    res += count;
                }
            for (j = n - 1; j > i; j--)
                for (k = 0; k < m; k++)
                    mat[j][k] &= mat[j - 1][k];
        }
        return res;
    }
};
// @lc code=end

