/*
* @lc app=leetcode.cn id=剑指 Offer 57 - II lang=cpp
*
* [剑指 Offer 57 - II] 和为s的连续正数序列
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int i = 1; i <= limit; ++i) {
            for (int j = i;; ++j) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                }
                else if (sum == target) {
                    res.clear();
                    for (int k = i; k <= j; ++k) res.emplace_back(k);
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};

// @lc code=end

