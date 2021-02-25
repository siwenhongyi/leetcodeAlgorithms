/*
* @lc app=leetcode.cn id=1647 lang=cpp
*
* [1647] 字符频次唯一的最小删除次数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minDeletions(string s) {
        vector<int> pos(26, 0);
        for (auto& c : s)
            pos[c - 'a']++;
        sort(pos.begin(), pos.end());
        int res = 0;
        for (int i = 24; i >= 0; i--) {
            if (pos[i]) {
                while (pos[i]&&pos[i] >= pos[i + 1])
                    pos[i]--, res++; 
            }
        }
        return res;
    }
}; 

// @lc code=end

