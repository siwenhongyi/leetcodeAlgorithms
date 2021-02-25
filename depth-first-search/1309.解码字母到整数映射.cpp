/*
* @lc app=leetcode.cn id=1309 lang=cpp
*
* [1309] 解码字母到整数映射
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string freqAlphabets(string s) {
        if(s.empty())
            return s;
        int i = 0,n = s.size();
        int t;
        string res;
        for(int i = 0;i<n;i++){
            if(s[i]>='3')
                res+= 'a'+s[i]-'1';
            else if(i+2<n&&s[i+2]=='#'){
                int t = (s[i]-'0')*10 + (s[i+1]-'0');
                res += 'a' + t - 1;
                i+=2;
            }
            else
                res += 'a' + s[i] - '1';              
        }
        return res;
    }
};
// @lc code=end

