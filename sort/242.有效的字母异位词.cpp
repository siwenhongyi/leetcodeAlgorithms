/*
* @lc app=leetcode.cn id=242 lang=cpp
*
* [242] 有效的字母异位词
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> res(26,0);
        for(auto&c:s)
            res[c-'a']++;
        for(auto &c:t)
            if(!res[c-'a']--)
                return false;
        return count(res.begin(),res.end(),0)==26;
        
    }
};
// @lc code=end

