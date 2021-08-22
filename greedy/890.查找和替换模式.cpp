/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */
#include "head.h"
using namespace std;

// @lc code=start
class Solution {
private:
     bool check(string&s,string&t) {
         unordered_map<char,char> ss,tt;
         int n = s.size();
         char a,b;
         for(int i = 0;i<n;i++) {
             a = s[i],b=t[i];
            auto index = ss.count(s[i]);
            auto tindex = tt.count(t[i]);
            if(!index&&!tindex) {
                ss[s[i]] = t[i];
                tt[t[i]] = s[i];
                continue;
            }
            if(index&&ss[s[i]] == t[i]&&tindex&&tt[t[i]] == s[i]){
                continue;
            }
            return false;
         }
         return true;
     }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto&it:words) {
            if(it.size()==pattern.size()&&check(it,pattern))
                res.push_back(it);
        }
        return res;
    }
};
// @lc code=end

