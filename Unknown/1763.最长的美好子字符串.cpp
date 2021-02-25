/*
* @lc app=leetcode.cn id=1763 lang=cpp
*
* [1763] 最长的美好子字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool check(vector<int>& x, vector<int>& y) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) return false;
        }
        return true;
    }
    bool check(string& s, int i, int j) {
        vector<int> x(26, 0), y(26, 0);
        for (int index = i; index <= j; index++) {
            auto t = s[index];
            if (t >= 'A' && t <= 'Z')
                y[t - 'A']=1;
            else
                x[t - 'a']=1;
        }
        return check(x, y);
    }
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n) {
                if (j - i + 1 > res.size() && check(s, i, j))
                    res = s.substr(i, j - i + 1);
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

