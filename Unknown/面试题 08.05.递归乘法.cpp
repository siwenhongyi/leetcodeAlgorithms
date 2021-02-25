/*
* @lc app=leetcode.cn id=面试题 08.05 lang=cpp
*
* [面试题 08.05] 递归乘法
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int multiply(int A, int B) {
        int res = 0;
        int a = max(A, B), b = min(A, B);
        if (b == 0)
            return 0;
        else if (b == 1)
            return a;
        bitset<32> t(b);
        for (int i = 0; i < 32; i++) {
            if (t[i] == 0)
                continue;
            int temp = (1 << i);
            for (int j = 0; j < temp; j++) {
                res += a;
            }
        }
        return res;
    }
};

// @lc code=end

