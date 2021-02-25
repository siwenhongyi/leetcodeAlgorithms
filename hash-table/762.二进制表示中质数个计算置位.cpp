/*
* @lc app=leetcode.cn id=762 lang=cpp
*
* [762] 二进制表示中质数个计算置位
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool p(int x) {
        if (x < 2)
            return false;
        for (int i = 2; i <= sqrt(x); i++)
            if (x % i == 0)
                return false;
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++){
            bitset<31> x(i);
            res += p(x.count());
        }
        return res;
    }
};
// @lc code=end

