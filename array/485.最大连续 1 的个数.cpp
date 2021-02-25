/*
* @lc app=leetcode.cn id=485 lang=cpp
*
* [485] 最大连续 1 的个数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0,i,j,n=nums.size();
        i=j=0;
        while(i<n){
            if(nums[i]==0){
                i++;
                continue;
            }
            j =i;
            while(j<n&&nums[j]==1)
                j++;
            res = max(res,j-i);
            i=j;
        }
        return res;
    }
};
// @lc code=end

