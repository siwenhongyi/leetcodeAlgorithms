/*
* @lc app=leetcode.cn id=953 lang=cpp
*
* [953] 验证外星语词典
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
    map<char,int> dic;
public:
    bool fun(string &a,string &b){
        int n = min(a.size(),b.size()),i=0;
        while(i<n&&a[i]==b[i])
            i++;
        if(i!=n)
            return dic[a[i]]<dic[b[i]];
        else
            return a.size()<=b.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int j = 1,n=words.size();
        bool res = true;
        for(auto &c:order)
            dic[c]=j++;
        j = 1;
        while(j<n&&res){
            res = fun(words[j-1],words[j]);
            j++;
        }
        return res;
    }
};
// @lc code=end

