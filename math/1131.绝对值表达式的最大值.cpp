/*
* @lc app=leetcode.cn id=1131 lang=cpp
*
* [1131] 绝对值表达式的最大值
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        int t, n = a.size();
        for (int i = 0; i < n; i++) {
            t = a[i] + b[i];
            b[i] -= a[i];
            a[i] = t;
        }
        int amin, amax, bmin, bmax, res = 0;
        amin = min(a[0], a[1] + 1), amax = max(a[0], a[1] - 1);
        bmin = min(b[0], b[0] + 1), bmax = max(b[0], b[1] - 1);
        res = 1 + max(abs(a[0] - a[1]), abs(b[0] - b[1]));
        for (int i = 2; i < n; i++) {
            res = max(res, i + max(max(a[i] - amin, amax - a[i]), max(b[i] - bmin, bmax - b[i])));
            amin = min(amin, i + a[i]), amax = max(amax, a[i] - i);
            bmin = min(bmin, i + b[i]), bmax = max(bmax, b[i] - i);
        }
        return res;
    }
};
// @lc code=end

