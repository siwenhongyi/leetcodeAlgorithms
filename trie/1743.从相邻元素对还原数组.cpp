/*
* @lc app=leetcode.cn id=1743 lang=cpp
*
* [1743] 从相邻元素对还原数组
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& tp) {
        unordered_map<int,vector<int>> pos;
        unordered_set<int> vis;
        int first = 0;
        for(const auto&it:tp) {
            pos[it[0]].push_back(it[1]);
            pos[it[1]].push_back(it[0]);
            vis.insert(it[0]);
            vis.insert(it[1]);
        }
        int n = vis.size();
        vis.clear();
        vector<int> res;
        for(auto&[a,b]:pos) if(b.size() == 1){first = a;break;}
        res.push_back(first);
        vis.insert(first);
        while(res.size()!=n) {
            for(auto&iter:pos[first]){
                if(vis.count(iter)) continue;
                else {
                vis.insert(iter);
                res.push_back(iter);
                first = iter;
                break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

