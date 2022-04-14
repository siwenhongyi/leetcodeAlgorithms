/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "head.h"
using namesapce std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> num,path;
    int n;
    void dfs(int index,const int pre,const bool flag) {
        if (index == n) {
            res.push_back(path);
            return;
        }
        auto&& curr = num[index];
        dfs(index + 1, curr, false);
        if (!flag && curr == pre) return;
        path.emplace_back(curr);
        dfs(index + 1, curr, true);
        path.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        if (n == 0) 
            return {};
        num.swap(nums);
        sort(num.begin(), num.end());
        dfs(0, num[0]-1, true);
        return res;
    }
};
// @lc code=end

