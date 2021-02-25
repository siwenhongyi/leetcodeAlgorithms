/*
* @lc app=leetcode.cn id=349 lang=cpp
*
* [349] 两个数组的交集
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& x, vector<int>& y) {
        if (x.empty() || y.empty())
            return {};
        if (x.size() > y.size())
            x.swap(y);
        set<int> a;
        for (auto& it : x)
            a.insert(it);
        set<int> res;
        for (auto& it : y)
            if (a.count(it))
                res.insert(it);
        vector<int> ans;
        for (auto& it : res)
            ans.push_back(it);
        return ans;
    }
};

// @lc code=end

