/*
* @lc app=leetcode.cn id=1400 lang=cpp
*
* [1400] 构造 K 个回文字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char, int> pos;
        for (auto& it : s)
            pos[it]++;
        int single = 0, n = s.size();
        for (auto& it : pos)
            if (it.second % 2)
                single++;
        return (k >= single && k <= n);
    }
};

// @lc code=end

