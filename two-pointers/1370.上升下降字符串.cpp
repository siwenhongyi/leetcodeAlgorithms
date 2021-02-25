/*
* @lc app=leetcode.cn id=1370 lang=cpp
*
* [1370] 上升下降字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string sortString(string s) {
        vector<int> ch(26,0);
        string res;
        int cnt = s.size();
        for(auto&it:s) ch[it-'a']++;
        while(cnt){
            for(int i = 0;i<26;i++)
                if(ch[i]){
                    res.push_back('a' + i);
                    cnt--,ch[i]--;
                }
            for(int i = 25;i>=0;i--){
                if(ch[i]){
                    res.push_back('a' + i);
                    cnt--,ch[i]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

