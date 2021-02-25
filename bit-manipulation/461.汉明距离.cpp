/*
* @lc app=leetcode.cn id=461 lang=cpp
*
* [461] 汉明距离
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        bitset<32> res(x);
        return res.count();
    }
};
// @lc code=end

