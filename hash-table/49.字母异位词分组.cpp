/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res(1);
        unordered_map<string, int> pos;
        string t;
        for (auto &i : strs)
        {
            t = i;
            sort(t.begin(), t.end());
            int index = pos[t];
            if (!index)
            {
                pos[t] = res.size();
                res.push_back({i});
            }
            else
                res[index].push_back(i);
        }
        res.erase(res.begin());
        return res;
    }
};

// @lc code=end
