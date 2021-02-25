/*
* @lc app=leetcode.cn id=41 lang=cpp
*
* [41] 缺失的第一个正数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;
        int n = nums.size();
        vector<unsigned int> pos(n / 32 + 1, 0);
        int id, r, m = 1;
        pos[0] = 1;
        for (auto& it : nums) {
            if (it <= 0 || it > n)
                continue;

            if (it >= m)
                m = it + 1;
            if (it > 0 && it <= n) {
                id = it / 32;
                r = it % 32;
                pos[id] |= (1 << r);
            }
        }
        for (int i = 0; i < pos.size(); i++) {
            auto x = pos[i] ^ (UINT32_MAX);
            if (x) {
                bitset<32> xx(x);
                for(int i = 0;i<32;i++)
                    if (xx[i] == 1) {
                        id = i;
                        break;
                    }
                m = i * 32 + id;
                break;
            }
        }
        return m;
    }
};

// @lc code=end

