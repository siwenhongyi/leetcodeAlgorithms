/*
* @lc app=leetcode.cn id=1638 lang=cpp
*
* [1638] 统计只差一个字符的子串数目
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool check(string& s, string& t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i])
                if (++cnt > 1)
                    return false;
        return cnt == 1;
    }
    int countSubstrings(string s, string t) {
        vector<string> sub;
        int res = 0;
        for (int i = 0; i < t.size(); i++)
            for (int j = i; j < t.size(); j++) 
                sub.push_back(t.substr(i, j - i + 1));
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                auto a = s.substr(i, j - i + 1);
                for (auto& it : sub)
                    if (it.size() == a.size() && check(a, it))
                        res++;
            }
        }
        return res;
    }
};

// @lc code=end

