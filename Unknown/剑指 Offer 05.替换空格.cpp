/*
* @lc app=leetcode.cn id=剑指 Offer 05 lang=cpp
*
* [剑指 Offer 05] 替换空格
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it == ' ')
                res += "%20";
            else
                res += *it;
        }
        return res;
    }
};
// @lc code=end

