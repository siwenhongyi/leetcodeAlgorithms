/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if( n == 0) return 0;
        if( n <=2) return 1;
        vector<int> nums(n+1,1);
        nums.front() = 0;
        int res = 1;
        for(int i = 2;i<=n;i++) {
            if(i&1) {
                nums[i] = nums[i/2] + nums[i/2+1];
            }else {
                nums[i] = nums[i/2];
            }
            res = max(res,nums[i]);
        }
        return res;
    }
};
// @lc code=end

