/*
* @lc app=leetcode.cn id=1365 lang=cpp
*
* [1365] 有多少小于当前数字的数字
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                else if (nums[j] < nums[i])
                    t++;
            }
            res[i] = t;
        }
        return res;
    }
};

// @lc code=end

