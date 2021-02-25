/*
* @lc app=leetcode.cn id=659 lang=cpp
*
* [659] 分割数组为连续子序列
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<bool> last(n);
        vector<int> len(n);
        for (int i = 0; i < n; i++) {
            //if (i < 2) { 
            //    last[i] = false, len[i] = 1 + int(i && nums[i] > nums[i - 1]); 
            //    continue;
            //}
            int index = -1, m = INT_MAX;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] == nums[i])continue;
                if (nums[j] != nums[i] - 1)break;
                if (!last[j]) {
                    if (len[j] + 1 < m) m = len[j] + 1, index = j;
                }
            }
            last[i] = false;
            if (index == -1)len[i] = 1;
            else last[index] = true, len[i] = m;
        }
        for (int i = 0; i < n; i++) {
            if (!last[i] && len[i] < 3) return false;
        }
        return true;
    }
};
// @lc code=end

