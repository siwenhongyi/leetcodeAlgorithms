/*
* @lc app=leetcode.cn id=581 lang=cpp
*
* [581] 最短无序连续子数组
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t(nums);
        sort(t.begin(),t.end());
        int n = t.size();
        for(int i = 0;i<n;i++){
            if(t[i]==nums[i])
                continue;
            int j = i+1,k;
            bool b = true;
            while(b){
                while(j<n&&nums[j]!=t[j])
                    j++;
                k = j;
                while(k<n&&nums[k]==t[k])
                    k++;
                if(k==n)
                    return j-i;
                j = k;
                
            }
        }
        return 0;
    }
};
// @lc code=end

