/*
* @lc app=leetcode.cn id=1207 lang=cpp
*
* [1207] 独一无二的出现次数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> pos;
        unordered_set<int> res;
        for(auto &i:arr)
            pos[i]++;
        for(auto&i:pos)
            res.insert(i.second);
        return pos.size()==res.size();
    }
};
// @lc code=end

